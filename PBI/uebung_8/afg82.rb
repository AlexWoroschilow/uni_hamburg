#!/usr/bin/env ruby

class Converter
  def range(tStart, tEnd)
    @range = Range.new(tStart, tEnd)
    @range.each {     
      |celsius| printf("c = %.2f f = %.2f\n", celsius, celciusToFahrengeit(celsius))
    }
  end

  def celciusToFahrengeit(t = 0)
    return (t * 9.0) / 5.0 + 32.0;
  end

end

(Converter.new()).range(1, 100)

