#!/usr/bin/ruby

class Step
  attr_reader :i
  attr_reader :j

  def initialize(i, j)
    @i = i
    @j = j
  end
end

class Decorator
  def matrix(matrix)
    matrix.each do |line|
      print(line)
      print("\n")
    end
  end
end

class Stack
  def initialize
    @store = Array.new
  end

  def pop
    return @store.pop
  end

  def push(element)
    @store.push(element)
  end

  def size
    @store.size
  end
end


class EDistLazy
  @stack = nil
  @matrix = nil
  @decorator = nil

  def initialize (stack, decorator)
    @stack = stack
    @decorator = decorator
  end

  def fill_stack(i, j, seq1, seq2)

    char1 = seq1[i-1]
    char2 = seq2[j-1]

    if i < 0 or j < 0
      return true
    end

    @stack.push(Step.new(i, j))

    if char1 == char2
      fill_stack(i-1, j-1, seq1, seq2)
      return
    end

    fill_stack(i, j-1, seq1, seq2)
    fill_stack(i-1, j, seq1, seq2)
    fill_stack(i-1, j-1, seq1, seq2)
    return
  end

  def eDist(seq1, seq2)

    m = seq1.size;
    n = seq2.size;

    fill_stack(m, n, seq1, seq2)

    @matrix = Array.new(m + 1) {
      Array.new(n + 1) { 0 }
    }

    while element = @stack.pop

      i = element.i
      j = element.j

      if i == 0 and j == 0
        @matrix[i][j] = 0
        next
      elsif i == 0
        @matrix[i][j] = @matrix[i][j-1] + 1
        next
      elsif j == 0
        @matrix[i][j] = @matrix[i-1][j] +1
        next
      end

      char1 = seq1[i-1]
      char2 = seq2[j-1]

      if (char1 == char2)
        @matrix[i][j] = @matrix[i-1][j-1]
      elsif @matrix[i-1][j-1] > @matrix[i-1][j]
        @matrix[i][j] = @matrix[i-1][j] + 1
      else
        @matrix[i][j] = [
            @matrix[i-1][j-1],
            @matrix[i-1][j],
            @matrix[i][j-1],
        ].min + 1
      end
    end

    @decorator.matrix(@matrix)

  end

end


(EDistLazy.new(Stack.new, Decorator.new)).eDist('freizeit', 'zeitgeist')
(EDistLazy.new(Stack.new, Decorator.new)).eDist('aabaa', 'aaaba')
(EDistLazy.new(Stack.new, Decorator.new)).eDist(
    'acgtgagtatagatagatgccccagagggttagacagatagaccgatgagacgagtagacggagtttagagagatgatgc',
    'acgtgattatagatagatgccccagagcgttagacagataaaccgatgagacgtgtagacggagttcagagagatgatgc'
)