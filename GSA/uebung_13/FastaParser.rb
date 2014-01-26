class FastaParser
  def initialize (alphabet)
    @string = ''
    @lenth = nil
    @alphabet = alphabet
  end
  
  def set_line(line)
    @string = line
  end
  # check string alphabet 
  # and other
  def validate()
    if (sequenz?)
      @string.each_char do |char|
        if(!@alphabet.match(/#{char}+/))
          raise "String alphabet is not correct\nChar: #{char}\nString: #{@string}"            
        end
      end
    end
  end
  def header?()
    return @string.match(/^(>.*)$/)
  end
  def header()
    return @string.gsub(/>/, '').chomp
  end
  def comment?()
    return  @string.match(/^(#.*)$/)
  end
  def comment()
    return @string.gsub(/#/, '').chomp
  end
  def sequenz?()
    return !@string.match(/^(>.*)|(#.*)$/);
  end
end
