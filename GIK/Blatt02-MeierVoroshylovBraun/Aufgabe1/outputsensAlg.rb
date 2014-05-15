#!/usr/bin/env ruby

#=============================================#
#      
#  Genominformatik - assignment 2          
#                                      
#  Aufgabe 2.1 - ouput sensitive algorithm        
#                                           
#  group:   Oleksandr Voroshylov,        
#           Tobias Meier,                
#           Felix Braun   
#
#=============================================#


# lcplen for p = u[i..m] and q = v[j..n]
def lcplen(p, q, m, n)

  length = 0

  # length of the shorter substring
  x = [m, n].min

  length = 0

  (0...x).each do |i|

    # iterate till missmatch
    if p[i] != q[i]

      # and return length if missmatch has been found
      return length
    else

      # increase length if no missmatch 
      length += 1
    end
  end

  # return length if one of the sequences reaches its end
  return length
end


# get a certain front value
def outsense_next_front(front, h, d, u, v, m, n)

  # define l according to the script 
  # "||" statements for handling "nil" values
  # in case of front[x] beeing nil, an empty array [] 
  # will be returned. If [x] key exists but array 
  # hasn't got a [d-1] index, 0 (lowest possible i value)
  # will be returned to the ".max" method 
  l = [(front[h-1] || []) [d-1] || 0,
      ((front[h+1] || []) [d-1] || -1) + 1,
      ((front[h] || []) [d-1] || -1) + 1].max

  # define i an j indices according to the script
  i = l + 1
  j = l + h + 1

  # define substrings based on i and j
  # assign empty string if i > m or j > n
  # (on the edges of the matrix)
  p = u[i..m] || ""
  q = v[j..n] || ""

  # return new i value of the current front
  return(l + lcplen(p, q, p.length, q.length))
end


# calculate all fronts till edist has been obtained
def outsense_edist(u, v)

  # initialize m and n
  m = u.length
  n = v.length

  # create hash of arrays where 
  # hash.key holds h and array index holds d
  # thus hash[h][d] = front(h, d) = i
  front = Hash.new

  ((-m)..n).each do |key|
    front[key] = Array.new
  end

  # initialize d with 0 for the first front
  d = 0

  # calculate front(0, 0)
  front[0][d] = lcplen(u, v, m, n)

  # inserting spaces infront of each sequence 
  # to simulate the first row and column  
  # of a m+1 x n+1 matrix
  u.insert(0, " ")
  v.insert(0, " ")

  # m and n do not have to be updated since they 
  # will be handled as the actual sequence length 
  # and not as array length 

  # till front(n - m, d) = m 
  while front[n-m][d] != m

    # increase d
    d += 1

    # fronts calculated according to script
    ((-d)..d).each do |h|

      # if hashkey h doesn't exist 
      # there is not need to calculate it
      next if front[h] == nil

      front[h][d] = outsense_next_front(front, h, d, u, v, m, n)
    end
  end

  # return current d value
  return d
end