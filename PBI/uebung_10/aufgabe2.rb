#!/usr/bin/ruby

# Fasta header object 
class FastaHeader
  def initialize ()
    @string = nil
  end
  def from_string(string)
    @string = string
  end
  def is_empty? ()
    return @string == nil;
  end
  def to_s()
    return @string
  end
end

# Fasta sequenz object 
class FastaSequenz
  def initialize ()
    @sequenz = nil
  end
  def from_string(string)
    @sequenz = string
  end
  def is_empty? ()
    return @sequenz == nil;
  end
  def to_s()
    return @sequenz
  end
end

# Fasta object to 
# store fasta sequenz and header
class Fasta
  def initialize ()
    @header = FastaHeader.new
    @sequenz = FastaSequenz.new
  end
  def set_header (string)
    @header.from_string(string)
  end
  def set_sequenz (string)
    @sequenz.from_string(string)
  end
  def get_sequenz ()
    return @sequenz.to_s
  end
  # Check for header string
  def is_header? (string)
    if(string.match(/>/))
      return true
    end
    return false
  end
  def is_complete? ()
    if(@header.is_empty? != true and @sequenz.is_empty? != true )
      return true
    end
    return false
  end
  def to_s ()
    return "#{@header.to_s}\n#{@sequenz.to_s}"
  end
end

# Factory class to build  
# Fasta objects collection from file
class FastaFactory
  def initialize (file)
    @template = Fasta.new
    @collection = Array.new
    File.new(file, 'r').each_line do |line|
      append_line(line)
    end
  end
  def append_line(string)
    if (@template.is_header?(string))
      @template.set_header(string.chomp)
    else
      @template.set_sequenz(string.downcase)
    end
    if (@template.is_complete?)
      @collection.push(@template)
      @template = Fasta.new
    end
  end
  def collection()
    return @collection
  end
end


# Define RNA Sequenz class
# try to find UTR parts
class RNASequenz
  def initialize (sequenz)
    @sequenz = sequenz
  end
  # Method to find UTR parts
  def mark_utr()
    posStart = 0
    # Try to find start codon
    while ((posStart = @sequenz.index(/aug/, posStart)))
      # Try to find stop codon, increase position to ignore stop codon symbols
      if((posEnd = @sequenz.index(/(uaa)|(uag)|(uga)/, posStart + 3)))
        # Build UTR with start and end positions
        part = @sequenz[posStart, posEnd - posStart + 3]
        # Replace lower case to upper case 
        @sequenz.gsub!(part, part.upcase)
        # Increase start position to ignore stop codons
        posStart = posEnd + 3
      end  
    end
    return @sequenz.to_s
  end
end


(FastaFactory.new('mRNA.fas')).collection().each do |fasta|
  # Initialize new sequenz
  rna = RNASequenz.new(fasta.get_sequenz)
  # Replace fasta sequenz to new modified sequenz
  fasta.set_sequenz(rna.mark_utr)
  puts fasta.to_s
end




