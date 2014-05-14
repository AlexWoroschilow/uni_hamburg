#!/usr/bin/ruby
require "./Fasta.rb"
require "./FastaParser.rb"
require "./RNASequenz.rb"
require "./FastaIterator.rb"
require "./transcription_table.rb"


if __FILE__ == $0
  
  file      = ARGV[0] ? ARGV[0] : 'multifasta.fasta'
  alphabet  = ARGV[1] ? ARGV[1] : "GCAT"
  
  (FastaIterator.new(file, FastaParser.new(alphabet))).each do |fasta, header, sequenz|
    
    sequenz_rna = sequenz.upcase.tr('ATGC', 'UACG')  
    
    puts "DNA: #{sequenz}"
    puts "RNA: #{sequenz_rna}"
    
    
    RNASequenz.new(sequenz_rna).each_orf do |orf|
      puts orf
      puts TranscriptionTable.translate(orf)
    end
  end
end



# DNA: CGTAGCATGATAATTCGTTTAGCGAATGAGTAGAGG
# RNA: GCAUCGUACUAUUAAGCAAAUCGCUUACUCAUCUCC
# DNA: GATCGCGTAGCTAGCTAGCTTAGCGCTAGCTAGCGCTAGGTAAGCAAAAA
# RNA: CUAGCGCAUCGAUCGAUCGAAUCGCGAUCGAUCGCGAUCCAUUCGUUUUU
# DNA: GCTAGCTAGGAGCTAGCTAGCTAGCTAGCTAGC
# RNA: CGAUCGAUCCUCGAUCGAUCGAUCGAUCGAUCG
# DNA: CGTCGTAGCCATGGCAACATGCCACGAAGACTTCGCCAGCACAGCGTTTATCCTCGAAAGTTAGCGTCGTAGAAAAAA
# RNA: GCAGCAUCGGUACCGUUGUACGGUGCUUCUGAAGCGGUCGUGUCGCAAAUAGGAGCUUUCAAUCGCAGCAUCUUUUUU
