#!/usr/bin/env ruby

$LOAD_PATH << './'
require 'Blosum62.rb'

# Fehler
if ARGV.length != 3
  STDERR.puts "Usage: \"#{$0} <protein sequence> <q> <k>\"."
  exit 1

elsif !(ARGV[1] =~ /^\d+$/) || !(ARGV[2] =~ /\d+$/)
  STDERR.puts "Please chose valid numbers for <q> and <k>."
  exit 1

elsif !(ARGV[0] =~ /^[LVIFKREDAGSTNQYWPHMCX]*$/)
  STDERR.puts "Invalid protein sequence."
  exit 1
end

seq = ARGV[0]
q = ARGV[1].to_i
k = ARGV[2].to_i

@m = Blosum62Matrix.new

score = 0
@env = []
@tempenv = []
word = ""
@words = []
orig = ""



def get_words(orig, word, q, k, max_score, a)
  
  # Rekursionsabbruch
  if (q == 0)
    @tempenv.push([word, max_score, a])
  
  else
    
    # Bestimmung der AS in der Originalsequenz
    y = orig[orig.length - q]
    21.times do |x|
      
      # Maximal zu erreichender Score bei entsprechendem Austausch der AS
      new_score = max_score + @m.getscore(@m.get_as(x), y) - @m.getscore(y, y)
      
      # Aussortierung unnoetiger q-Worte
      if new_score >= k 
        nword = word + @m.get_as(x)
        
        # Rekursiver Aufruf fuer das naechste Zeichen
        get_words(orig, nword, (q - 1), k, new_score, a)
      else
        next
      end
    
    end
  end
end

(seq.length - (q - 1)).times do |a|
  
  score = 0
  orig = seq[a...(q + a)]
  
  # Maximaler Score bei exakter Uebereinstimmug der AS
  q.times do |b|
    score += @m.getscore(seq[b+a],seq[b+a])
  end
  
  # Berechnung aller q-Worte der entsprechenden Position
  get_words(orig, word, q, k, score, (a + 1))
  
  # Sortierung aller Elemente des Indeces a
  @tempenv.sort!
  @tempenv.each do |element|
    @env.push(element)
  end
  @tempenv = []
end

# Ausgabe
@env.each do |w, v, u|
  puts "#{w}\t#{v}\t#{u}"
end
