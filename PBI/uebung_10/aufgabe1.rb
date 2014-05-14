#!/usr/bin/ruby


result = Hash.new

File.new('sumzeile.data', 'r').each_line do |line|
  
  regexp = /([\w]?)=([\d]*)[\s]*([\w]?)=([\d]*)[\s]*([\w]?)=([\d]*)[\s]*([\w]?)=([\d]*)/
  
  match = regexp.match(line).to_a
  
  # get index from parsed string
  index = match.fetch(2).to_i
  # get summe from parsed string
  summe = match[4].to_i + match[6].to_i + match[8].to_i
  
  # initialisieren result array
  if (result.has_key?(index) == false)
    result.store(index, 0)
  end
  
  # store ergebnisse here
  result.store(index, summe + result[index])    
end


result.each do |key, value|
  puts "[#{key}]=#{value}"
end 
