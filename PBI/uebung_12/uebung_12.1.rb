#!/usr/bin/ruby
#!/usr/bin/ruby
require "./Fasta.rb"
require "./FastaParser.rb"
require "./FastaMSAParser.rb"
require "./FastaIterator.rb"

if __FILE__ == $0
  
  file      = ARGV[0] ? ARGV[0] : 'multifasta.fasta'
  alphabet  = ARGV[1] ? ARGV[1] : "GCAT-"
  
  begin
    # define Fasta MSA parser object 
    # with amino-acids alphabet 
    parser = FastaParser.new(alphabet)
    # read fasta file, parse and get fasta object 
    (FastaIterator.new(file, parser)).each do |fasta|
      puts "#{fasta.header}\t#{fasta.sequenz}"
      # puts fasta.to_str
    end
  # catch exception and display 
  # as a message on screen
  rescue Exception => ex  
    puts ex
  end
  
end



