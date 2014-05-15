#!/usr/bin/env ruby

#
#      
#  Genominformatik - assignment 2          
#                                      
#  Aufgabe 2.1 - ouput sensitive algorithm        
#                                           
#  group:   Oleksandr Voroshylov,        
#           Tobias Meier,                
#           Felix Braun   
#
#


# lcplen for p = u[i..m] and q = v[j..n]
def lcplen(p, q, m, n)

  length = 0

  # length of the shorter substring
  x = [m, n].min

  (0...x).each do |i|

    # increase length if no missmatch 
    # in the previous iteration
    length = i

    # iterate till missmatch
    if p[i] != q[i]
      
      # and return length if missmatch has been found
      return length
    end
  end

  # return length if one of the sequences reaches its end
  return length
end


# get a certain front value
def outsense_next_front(front, h, d, u, v, m, n)

  # define l according to the script
  # "||" statements for handling "nil" values
  # in case of front[x][y] beeing nil, 
  # -1 will be returned to the ".max" method
  l = [front[h-1][d-1] || -1,
       (front[h+1][d-1] || -2) + 1,
       (front[h-1][d] || -2) + 1].max

  # define i an j indices
  i = l + 1
  j = l + h + 1

  # define substrings based on i and j
  # assign empty string if i > m or j > n
  # (on the edges of the matrix)
  p = u[i...m] || ""
  q = v[j...n] || ""

  # return new i value of the current front
  return ((l + lcplen(p, q, p.length, q.length)))
end


# calculate all fronts will edist has been obtained
def outsense_edist(u, v)

  # initialize m and n
  m = u.length
  n = v.length

  # create hash of arrays where 
  # hash.key holds h and array index holds d
  # thus hash[h][d] = front(h, d) = i
  front = Hash.new(Array.new)
  
  # initialize d with 0 for the first front
  d = 0

  # calculate front(0, 0)
  front[0][d] = lcplen(u, v, m, n)
  
  # till front(n - n, d) = m
  while front[n-m][d] != m-1

    # increase d
    d += 1
    
    # fronts calculated according to script
    ((-d)..d).each do |h|
      front[h][d] = outsense_next_front(front, h, d, u, v, m, n)
    end
  end

  # length of array with hash key m - n (= h) is 
  # as long as the index of its last entry (= d) + 1
  return (front[m-n].length - 1)
end