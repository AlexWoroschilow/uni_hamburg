#!/usr/bin/ruby
require "./Fasta.rb"
require "./FastaParser.rb"
require "./FastaMSAParser.rb"
require "./FastaIterator.rb"

class MSA
  def initialize ()
    @msa = Array.new
  end
  def append (sequenz)
    @msa.push(sequenz)
  end
  def consensus ()
    consensus = Array.new
    @msa.each do |sequenz|
      key = 0
      sequenz.each_char do |char|
        if(consensus[key] == nil)
          consensus[key] = MSAConsensusChar.new
        end
        (consensus[key]).append(char)
        key += 1
      end
    end
    return MSAConsensus.new(@msa, consensus)
  end
  def all_pair_score ()
    consensus = Array.new
    @msa.each do |sequenz|
      key = 0
      sequenz.each_char do |char|
        if(consensus[key] == nil)
          consensus[key] = MSAAllPairScoreChar.new
        end
        (consensus[key]).append(char)
        key += 1
      end
    end
    return MSAAllPairScore.new(@msa, consensus)
  end
  
end

class MSAAllPairScore
  def initialize (msa, collection)
    @msa = msa 
    @collection = collection
  end
  def sum()
    sum = 0
    @collection.each do |element|
      sum += element.sum
    end
    return sum
  end
end

class MSAAllPairScoreChar
  def initialize ()
    @count = nil
    @current = nil
    @collection = Array.new
  end
  def append (char)
    @collection.push(char)
  end
  def cost (char1, char2)
    if (char1 == char2)
      return 0
    end 
    return 1
  end
  def sum()
    sum = 0
    cache = Array.new
    @collection.each_index do |index1|
      cache.push(index1)
      @collection.each_index do |index2|
        if(cache.index(index2) != nil)
          next
        end
        char1 = @collection[index1]
        char2 = @collection[index2]
        sum += cost(char1, char2)
      end      
    end
    return sum
  end
end

class MSAConsensus
  def initialize (msa, consensus)
    @msa = msa
    @consensus = consensus
  end
  def distance()
    distance = 0
    @consensus.each do |cons|
      distance += cons.distance
    end
    return distance
  end
  def sequenz()
    sequenz = String.new    
    @consensus.each do |cons|
      sequenz.concat(cons.to_s)
    end
    return sequenz
  end
end

class MSAConsensusChar
  def initialize ()
    @count = nil
    @current = nil
    @collection = Hash.new
  end
  def append (char)
    if (@collection.has_key?(char))
      @collection[char] += 1
    else
      @collection[char] = 1
    end
    @collection.each_pair do |key, val|
      if (key == '-')
        next
      end
      if (@count == nil)
        @count = val
        @current = key
      end
      if (@count < val)
        @count = val
        @current = key        
      end
    end
  end
  def distance ()
    distance = 0
    @collection.each_pair do |key, val|
      if(@current != key)
        distance += val
      end
    end
    return distance
  end
  def to_s ()
    return @current
  end
end


if __FILE__ == $0

  file      = ARGV[0] ? ARGV[0] : 'tyrosine-kinasen.msa'
  alphabet  = ARGV[1] ? ARGV[1] : "QWERTYUIOPASDFGHJKLZCVBNM-"

  begin

    msa = MSA.new
    parser = FastaMSAParser.new(alphabet)
    
    (FastaIterator.new(file, parser)).each do |fasta, header, sequenz|
      puts "Sequenz: \t #{sequenz}" 
      msa.append(sequenz)
    end
    
    puts "\n"
    puts "Consensus: \t #{(msa.consensus).sequenz}"
    puts "\n"
    puts "Consensus distance: \t #{(msa.consensus).distance}" 
    puts "All pair sum score: \t #{(msa.all_pair_score).sum}" 


  rescue Exception => ex
    puts ex
  end
end

