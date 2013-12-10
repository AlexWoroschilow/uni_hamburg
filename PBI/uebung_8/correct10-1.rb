#!/usr/bin/env ruby

dna = 'ACGAATT\tACTTTAGC'

dna = dna.gsub!(/\\t/, " ") # we habe to remove \t from string
# Here is the starting DNA: ACGAATT ACTTTAGC
# Here is the starting DNA: ACGAATT ACTTTAGC
puts "Here is the starting DNA: #{dna}"

rna = dna.gsub!(/T/, "U") # we have to replace T with U
# Here is the result: ACGAAUU ACUUUAGC
# Here is the result: ACGAAUU ACUUUAGC
puts "Here is the result: #{rna}"
exit 0

