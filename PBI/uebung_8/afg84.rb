#!/usr/bin/env ruby

class DNA

  # Class constructor
  # speicher hier unsere Zeichenkette
  def initialize (seq)
    @seq = seq
  end
  
  # Ein funktion um Schmalztemperatur zu berechnen
  def sTemperatur()
    @len = @seq.length
    # Falls die Länge ungleich 0 ist
    # rechnen wir was nötig ist
    if @len
      # Falls die Länge der Zeichenkette kleiner oder gleich 14 ist 
      # rechnen wir das ein bisschen anders
      if(@len <= 14)
	return 4.0 * (occ(@seq, 'G') + occ(@seq, 'C')) + 2 * (occ(@seq, 'A') + occ(@seq, 'T'))
      # Falls die Länget des DNAs relativ gross ist 
      # dann rechnen wir das auch anders
      else 
	return 64.9 + 41.0 * (occ(@seq, 'G') + occ(@seq, 'C') - 16.4) / @len
      end
    end     
    return NIL
  end
  
  # Eine Hilffunktion 
  # rechnen die Anzahl der Vorkommen von Base b
  def occ(seq, b)
    # löchen alles anstatt was in b drin ist
    return seq.gsub(/^#{b}/, "").length
  end
  
end

# rechnen Schmalztemperatur und ausgeben mit 2 Zahlen nach dem Punkt
puts "#{'%.2f' % (DNA.new("AGCTGCAAAGTCGAT")).sTemperatur}"
  
