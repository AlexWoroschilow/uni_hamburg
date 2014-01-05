#!/usr/bin/ruby

class QGram
  # Class constructor
  # speicher hier unsere Zeichenkette
  def initialize (seq1, seq2, alphabet)
    @seq1 = seq1
    @seq2 = seq2
    @alphabet = alphabet.split(//)
    @list = Array.new
  end

  # Calculate qgram profile
  # for current sequence
  def qgram_profile (sequence, q)
    # Initialize qwort array
    qwort = Array.new
    # Initialize sequence profile array
    profile = Array.new

    # Laufzeit O(|sequence|)
    sequence.split(//).each { |char| 
      # Check is char in alphabet
      if (@alphabet.include?(char) != false)
	qwort.push(char)           
	if(qwort.length == q)
                            
	    # Create string from array 
	    substring = qwort.join('');
 
	    # Check existed qwort
	    if(@list.include?(substring) == false)
	      # add new qwort if not found
	      @list.push(substring)
	    end
	    
	    # Get unique qwort index
	    qwort_index = @list.index(substring)
                            
	    # Check existed qwort
	    if(profile.include?(substring) == false)
	      # If not exists mark as 1
	      profile[qwort_index] = 1
	    else
	      # If exists incrementieren
	      profile[qwort_index] += 1                            
	    end
                            
	    qwort.shift()
	end
      end
    }
    return profile
  end
  
  # Calculate distance
  def distance (q)
    result = 0
    profile1 = qgram_profile(@seq1,q)
    profile2 = qgram_profile(@seq2,q)    
        
    # Laufzeit O(|@list|)
    @list.each_with_index { |element, index|
                            
      if(profile1[index] == nil)
	  profile1[index] = 0
      end
                          
      if(profile2[index] == nil)
	  profile2[index] = 0
      end
                          
      result += (profile1[index] - profile2[index]).abs()
    }
        
    return result;
  end    
end

puts (QGram.new('aaccgatatagagac', 'aagggtagacgatgac', 'acgt')).distance(3)
