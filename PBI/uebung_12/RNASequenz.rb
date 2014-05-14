# Define RNA Sequenz class
# try to find UTR parts
class RNASequenz
  def initialize (sequenz)
    @sequenz = sequenz
  end
  # Method to find UTR parts
  def each_orf()
    start_position = 0
    
    # Try to find start codon
    while ((start_position = @sequenz.index(/(AUG)/i, start_position)))
      
      end_position = start_position
      while ( (triplet = @sequenz[end_position, 3]) and not triplet.match(/(UAA)|(UAG)|(UGA)/i))
        end_position += 3
      end
      yield @sequenz[start_position, end_position - start_position]
      start_position += end_position+3
    end
  end
end
