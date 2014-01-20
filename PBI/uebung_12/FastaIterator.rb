
class FastaIterator
  def initialize (file, parser)
    @file = file
    @parser = parser
    # check for fasta file and 
    # throw excemption if not found
    if(!File.exist?(@file))
      raise "File: \"#{@file}\" not found"
    end
  end
  def each()
    fasta = nil
    # read current file line by line
    # and fill fasta objects
    File.new(@file, 'r').each_line do |line|
      # Set current line to parser
      @parser.set_line(line.chomp)
      # check current line for
      # alphabet, length or solethind else 
      @parser.validate
      # if current fasta is empty
      # looking for header 
      # without header no fasta 
      if (fasta == nil)
        # hier looking for header
        if (@parser.header?)
          # hier create new fasta object
          # and fill new header line with empty comment and 
          # sequenz line
          fasta = Fasta.new(@parser.header, nil, nil)
        end
        next
      else
        # For each new fasta check each line for header string 
        # if header return current fasta object
        # and create new empaty fasta object
        if (@parser.header?)
          # hier return current fasta object 
          # for iterrator 
          yield fasta, fasta.header, fasta.sequenz 
          # hier create new fasta object and 
          # and fill new header string
          # with empty commend and sequenz string
          fasta = Fasta.new(@parser.header, nil, nil)
        # check for fasta comment
        # if comment, append to current fasta object
        elsif (@parser.comment?)
          # hier appen current line to fasta object
          # as comment
          fasta.append_comment(@parser.comment)
        # check for sequenz line 
        # if sequenz, fill current fasta object
        # with this sequenz
        elsif (@parser.sequenz?)
          # hier fill current fasta object 
          # with this sequenz
          fasta.append_sequenz(line.chomp)
        end
      end
    end
    # return last fasta object
    # wenn file endet
    yield fasta, fasta.header, fasta.sequenz
  end
end
