#!/usr/bin/env ruby
#
# GIK Uebungen Blatt 3

# Aufgabe 3.1:
#    Nussinov Algorithmus
#
# Gruppe: Voroshylov, Meier, Braun
#


class Nussinov

  @l_min = nil
  @cost=nil

  def initialize(l_min, cost)
    @cost = cost
    @l_min = l_min
  end

  def matrix (rna)

    matrix = Array.new(rna.length) {
      Array.new(rna.length) { nil }
    }

    (0...rna.length).each do |i|
      matrix[i][i] = 0
    end

    (0..rna.length-1).each do |l|
      (0...rna.length-l).each do |i|

        j=i+l
        if j-i-1 < @l_min
          matrix[i][j] = 0
        else

          variants = Array.new
          variants.push(matrix[i+1][j-1] + @cost.alpha(rna[i], rna[j]))
          variants.push(matrix[i+1][j])
          variants.push(matrix[i][j-1])

          var4 = Array.new
          (i+2..j-1).each do |k|
            var4.push((matrix[i][k-1] + matrix[k][j]))
          end

          variants.push(var4.min.to_s.to_i)

          matrix[i][j] = variants.min
        end
      end
    end

    return NussinovMatrix.new(rna, @cost, matrix)
  end
end

class NussinovCost
  @cost=nil

  def initialize(cost)
    if not cost.is_a? Hash
      raise('Wring object type for cost variable')
    end
    @cost = cost
  end

  def alpha(char1, char2)
    key = char1.to_s.concat(char2);
    if @cost[key].nil?
      return 999999
    end
    return @cost[key].to_s.to_i
  end
end

class NussinovPair
  @i=nil
  @j=nil

  def initialize(i, j)
    @i=i
    @j=j
  end

  def to_s
    return @i.to_s.concat(',').concat(@j.to_s)
  end
end


class NussinovMatrix
  @rna=nil
  @cost=nil
  @matrix=nil

  def initialize(rna, cost, matrix)
    @rna=rna
    @cost = cost
    @matrix = matrix
  end

  def energie ()
    return @matrix[0][@rna.length-1].to_s.to_i
  end

  def traceback (stack, i, j)
    if i < j
      if @matrix[i][j].equal? (@matrix[i+1][j-1].to_s.to_i+@cost.alpha(@rna[i], @rna[j]))
        stack.push(NussinovPair.new(i+1, j+1))
        self.traceback(stack, i+1, j-1)
      else
        if @matrix[i][j]==@matrix[i+1][j]
          self.traceback(stack, i+1, j)
        else
          if @matrix[i][j]==@matrix[i][j-1]
            self.traceback(stack, i, j-1)
          else
            (i+2...j-1).each do |k|
              if @matrix[i][j] == (@matrix[i][k-1] + @matrix[k][j])
                self.traceback(stack, i, k-1)
                self.traceback(stack, k, j)
                break
              end
            end
          end
        end
      end
    end
    return stack
  end

  def structure ()
    stack = Array.new
    self.traceback(stack, 0, @rna.length-1)
    return stack
  end

end

if __FILE__ == $0

  begin
    rna = ARGV[0]

    if rna.nil?
      raise('Bitte geben sie eine Zeichenkette ein, falls es moeglich ist')
    end

    matrix = Nussinov.new(3, NussinovCost.new({
                                                  'GC' => -3,
                                                  'CG' => -3,
                                                  'AU' => -2,
                                                  'UA' => -2,
                                                  'GU' => -1,
                                                  'UG' => -1,
                                              })).matrix(rna.upcase)

    puts matrix.structure()
    puts "Energie: ".concat(matrix.energie().to_s)

  rescue Exception => e

    puts e.to_s
  end


end