#
# Ruby script to set the most profitable ema and rsi parameters
# /!\ Very complex
#

$stdout.reopen("output.txt", "w")

tall = Time.now
STDERR.puts "Estimated time: #{(10 * 20 * 5 * 3) / 60} min"

elapsed = 0

mutex = Mutex.new
thr = Thread.new {
  loop do
    sleep(1)
    elapsed += 1
    per = (elapsed.to_f / (10.0 * 20.0 * 5.0 * 3.0)) * 100.0
    mutex.synchronize {
      STDERR.print "\r"
      STDERR.print per.to_i, "%"
    }
  end
}

for x in 5..15 do
  for y in 10..30 do
    for z in 10..15 do
      tab = [[x, y, z], 0]
      p tab[0]
      scriptstr = "def update()
{
    var macd = ema(#{x}, 0) - ema(#{y}, 0);
    var macd_p = ema(#{x}, 1) - ema(#{y}, 1);

    if (macd > 0 && macd_p < 0)
    {
        buy(percent_of_money(10));
    }
    else if (macd < 0 && macd_p > 0)
    {
        sell(all);
    }
    else if (rsi(#{z}, 0) >= 20 && rsi(#{z}, 1) < 20)
    {
        buy(percent_of_money(10));
    }
    else if (rsi(#{z}, 0) <= 80 && rsi(#{z}, 1) > 80)
    {
        sell(all);
    }
    else
    {
        wait();
    }
}
"
      f = File.new("strategy.chai", "w")
      f << scriptstr
      f.close
      system("ruby test.rb")
    end
  end
end

mutex.synchronize {
  STDERR.puts "Took #{Time.now - tall}.min minutes"
}

thr.join
