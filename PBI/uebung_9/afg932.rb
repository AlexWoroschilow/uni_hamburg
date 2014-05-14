#!/usr/bin/ruby


n = ARGV.at(0)
m = ARGV.at(1)

def summe_original (n)
  return (n * (n+1)) / 2
end 

def summe (n,m)  
  if (m <= n) 
    return summe_original(n) - summe_original(m-1)
  end
  return 0
end

puts "n: #{n}, m: #{m}, summe: #{summe(n.to_i,m.to_i)}"