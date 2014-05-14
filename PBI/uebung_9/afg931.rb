#!/usr/bin/ruby


n = ARGV.at(0)
m = ARGV.at(1)


def summe (n, m)
  if (m > n) 
    return 0;
  end
    
  r = 0
  while m and m <= n do
    r += m
    m += 1
  end
  return r
end 


puts "n: #{n}, m: #{m}, summe: #{summe(n.to_i,m.to_i)}"