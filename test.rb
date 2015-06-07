#!/bin/env ruby

MONEY = 1000000

script = [
    "titres/AMAZON1.TXT",
    "titres/BAC1.TXT",
    "titres/boeing5.txt",
    "titres/CISCO1.TXT",
    "titres/titres.txt"
]

puts("Investment: #{MONEY}\nEarning per day:")
script.each do |s|
    print(s + ": ")
    system("./trade_moulinette.php -p trade -f #{s} -m #{MONEY} -s")
    puts
end
