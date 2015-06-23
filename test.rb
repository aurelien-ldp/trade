#!/bin/env ruby

MONEY = 1000000

script = [
    "titres/AMAZON1.TXT",
    "titres/BAC1.TXT",
    "titres/boeing5.txt",
    "titres/CISCO1.TXT",
    "titres/titres.txt"
]

script.each do |s|
    system("./trade_moulinette.php -p trade -f #{s} -m #{MONEY} -s")
    puts
end
