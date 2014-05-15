#!/usr/bin/env ruby

#======================================================#
#      
#  Genominformatik - assignment 2          
#                                      
#  Aufgabe 2.1 - evaluate output sensitive algorithm       
#                                           
#  group:   Oleksandr Voroshylov,        
#           Tobias Meier,                
#           Felix Braun   
#
#======================================================#

$LOAD_PATH << './'
require 'outputsensAlg'


if ARGV.size != 1
  STDERR.puts "\n\tUsage: #{$0} <filename>\n\n"
  exit 1
else
  filename = ARGV[0]
  x = ARGV[1].to_i
end

begin
  file = File.new(filename,"r")
rescue => err
  STDERR.print "Could not open file #{filename}!\n"
  exit 1
end


file.each_line do |line|

  line.scan(/(\w+)\t(\w+)\t(\d+)/) do |entry|
    
    # calculate each edist from each sequence entry 
    # from the test sequence set and compare it
    # to the given value
    if outsense_edist(entry[0], entry[1]) != entry[2].to_i
      
      # exit if a single edist is wrong
      STDERR.puts "\n\tSomething went wrong...\n\n"
      exit 1
    end
  end
end

# congratulate if the algorithm passed the test
STDOUT.puts "\n\tCongratulations, it worked!\n\n"