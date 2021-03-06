#!/usr/bin/env ruby
#
# Genominformatik Uebungen - Blatt 2
#
# Aufgabe 2:
#    Recurrentz um zu berechnen S(n) die Anzahl
#   der potentiell moeglichen RNA-Sekundaerstrukturen
#   einer Sequenz der Laenge n
#
# Gruppe: Voroshylov, Meier, Braun
#
def structure_count(i, j, l)
  c=0
  if i < j
    c=1
    c = c + structure_count(i+1, j-1, l)
    c = c + structure_count(i+1, j, l)
    c = c + structure_count(i, j-1, l)
    x = (i+2)
    y = (j-1)
    if (y-x) >= l
      (x..y).each do |k|
        c = c + structure_count(i, k-1, l)
        c = c + structure_count(k, j, l)
      end
    end
  end
  return c
end

(0..16).each do |n|
  puts "n: #{n}, S(n): #{structure_count(1, n, 1)}"
end


