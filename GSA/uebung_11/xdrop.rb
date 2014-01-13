#!/usr/bin/ruby
load "sigma.rb"
load "fasta.rb"
load "hit.rb"


def extendhitleft (u, w, q, sigma, xd, i, j)
  r = 0
  xmax = 0
  scoresum = 0
  while ( i-r >= 0 and j-r >= 0) do
    scoresum = scoresum + sigma.get_cost(u[i-r], w[j-r])
    if scoresum < (xmax - xd)
      return r
    end
    if scoresum > xmax
      xmax = scoresum
    end
    r = r + 1
  end
  return r-1
end

def extendhitright (u, w, q, sigma, xd, i, j)
  r = 0
  xmax = 0
  scoresum = 0
  while ( i + r <= u.length and j + r <= w.length) do
    scoresum = scoresum + sigma.get_cost(u[i+r], w[j+r])
    if scoresum < (xmax - xd)
      return r
    end
    if scoresum > xmax
      xmax = scoresum
    end
    r = r + 1
  end
  return r-1
end

def xdrop (file_hits, q, xd, database, query, match, mismatch)
  
  query_sequenz     = (Fasta.new(query)).get_sequenz 
  database_sequenz  = (Fasta.new(database)).get_sequenz

  sigma = Sigma.new(match, mismatch)
  
  File.new(file_hits, 'r').each_line do |line|
    hit = Hit.new(line)
    
    i_start = hit.get_i
    i_end = hit.get_i + q

    j_start = hit.get_j
    j_end = hit.get_j + q

    # im Uebungsblatt steht dass die erste Zahl die Startposition in der Anfragesequenz ist
    # fast alle Startpositionen sind aber groesser als 3000 waehrend die Groesse der Anfragesequenz nur 519 ist
    # deshalb tausche ich diese werte  
    left = extendhitleft(database_sequenz, query_sequenz, q, sigma, xd, i_start, j_start)
    right = extendhitright(database_sequenz, query_sequenz, q, sigma, xd, i_end, j_end)
    
    i_start = i_start - left
    i_end =  i_end + right

    j_start = j_start - left
    j_end = j_end + right
    
    length = i_end - i_start + 1
    
    puts "(#{(i_start)}-#{(i_end)}) (#{(j_start)}-#{(j_end)}) length #{length}"
    puts "#{database_sequenz[i_start, length]}"
    puts "#{query_sequenz[j_start, length]}"
    puts ""
    
  end
end




if __FILE__ == $0
  
  file_hits = ARGV[0] ? ARGV[0]       : 'hits'
  q         = ARGV[1] ? ARGV[1].to_i  : 8
  xd        = ARGV[2] ? ARGV[2].to_i  : 10
  database  = ARGV[3] ? ARGV[3]       : 'testdb.fasta'
  query     = ARGV[4] ? ARGV[4]       : 'testquery.fasta'
  match     = ARGV[5] ? ARGV[5].to_i  : 1
  mismatch  = ARGV[6] ? ARGV[6].to_i  : -2
  
  xdrop(file_hits, q, xd, database, query, match, mismatch)
  
end





