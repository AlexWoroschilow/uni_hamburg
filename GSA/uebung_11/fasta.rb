class Fasta
  def initialize (file)
    @header = ''
    @sequenz = ''
    File.new(file, 'r').each_line do |line|
      if((string = line.match(/(>.*[\s]*)/)))
        @header = string
        next
      end
      if(@header)
        if(line.match(/(>.*[\s]*)/))
          break 
        end
        @sequenz = @sequenz.concat(line.chomp)
      end
    end
  end
  def get_sequenz()
    return @sequenz
  end
end
