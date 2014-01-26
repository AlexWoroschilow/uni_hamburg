class Fasta
  def initialize (header, comment, sequenz)
    @header = header
    @comment = comment == nil ? "Generated from example fasta generator" : comment
    @sequenz = sequenz == nil ? "" : sequenz 
  end
  def header()
    return @header
  end
  def sequenz()
    return @sequenz
  end
  def append_comment (string)
    @comment.concat(string)      
  end
  def append_sequenz (string)
    @sequenz.concat(string)  
  end
  def to_str ()
    return ">#{@header}\n##{@comment}\n#{@sequenz}\n"
  end
end
