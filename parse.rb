f = File.new("output.txt", "r")

mvps = []
mvp = []

loop do
  break if !(head = f.gets)
  n1 = f.gets.to_i
  n2 = f.gets.to_i
  n3 = f.gets.to_i
  n4 = f.gets.to_i
  n5 = f.gets.to_i
  a = (n1 + n2 + n3 + n4 + n5) / 5
  if a > 0
    mvps.push head.chomp
    mvp.push a
  end
end

puts mvps.at(mvp.index(mvp.max))
puts mvp.max
