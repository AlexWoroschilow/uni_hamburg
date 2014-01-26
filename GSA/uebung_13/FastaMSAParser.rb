require "./FastaParser.rb"

class FastaMSAParser < FastaParser
  # owerride base method 
  # to save a first sequenze length
  def set_line(line)
    @string = line
    # if string is a sequenz
    # save sequenz length
    # if current length not exists
    if (sequenz?)
      if(@lenth == nil)
        @lenth = @string.length
      end
    end
  end
  # validate fasta sequenz format
  # hier needs MSA fasta format 
  # check for alphabet and length
  def validate()
    # rung base method to check
    # for alphabet
    super
    # check for sequenz
    # an validate sequenz length
    if (sequenz?)
      # hier check sequenz length 
      if(@lenth != @string.length)
        raise "String length is not correct\nRequired lenght: #{@lenth}\nCurrent length: #{@string.length}\nString:#{@string}"            
      end
    end
  end
end

