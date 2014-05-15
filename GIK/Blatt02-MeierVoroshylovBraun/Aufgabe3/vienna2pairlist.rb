#!/usr/bin/env ruby
#
# Genominformatik Uebungen - Blatt 2
#
# Aufgabe 3:
#
#Input ist entweder ein einzelner Vienna-String
# 	-> vienna2pairlist ((..)(.))
# 	-> Output ist dann der entsprechende Pairlist-String und die Länge
#Oder Input ist eine Text-Datei mit beliebig vielen Vienna-Strings 
#	-> vienna2pairlist Vienna-examples.txt
#	-> Output ist Text-Datei vienna2pairlist_output.txt mit den entsprechenden
#	   Pairlist-Strings und ihrer Länge
#
#
# Gruppe: Voroshylov, Meier, Braun

$output = "{"

def v2p(vline, index = 1)
  vline.each_char do |c|
    if c == "("
      $stack.push(index)
    elsif c == ")"
      $tmp.push([$stack.pop, index])
    end
    index += 1
  end
end

def output(size)
  $tmp.sort! { |a, b| a[0] <=> b[0] }
  $tmp.each_with_index do |pair, i|
    $output += "("+ (pair[0]).to_s + "," + (pair[1]).to_s + ")" +
        ($tmp.size-1 == i ? "} " : ", ")
  end
  return $output + (size).to_s + "\n"
end

begin
  file = IO.readlines(ARGV[0])
  filew = File.open("vienna2pairlist_output.txt", "w")
rescue
  $stack = []
  $tmp = []
  v2p ARGV[0]
  puts output ARGV[0].size
else
  for line in file
    $stack = []
    $tmp = []
    $output = "{"
    v2p line
    filew.write(output line.size-1)
  end
ensure
  filew.close unless filew == nil
end





