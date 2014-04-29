# =========================================== #
# Genominformatik - Uebung 2
#
#        Aufgabe 2.1 
#             -
# Output sensitiver Algorithmus
# 
# Gruppe:  Oleksandr Voroshylov, 
#          Tobias Meier, 
#          Felix Braun 
# =========================================== #


#!/usr/bin/env ruby


# # Klasse eines fron wertes
# class front

#   @h
#   @d
#   @i

#   def initialize(h, d, i)

#     @h = h
#     @d = d
#     @i = i

#   end
# end


# speichern der front werte mit h als hash key
front = Hash.new


# hash[h] = (array[d] = i)
def front(h, d)

  return front[h][d]
  #l = max(front(h-1, d-1),
  #        front(h+1, d-1) + 1,
  #        front(h, d-1) + 1)
  #
  #return (l + lcplen(u[(l+1)...m], v[(h+l+1)...n]))
end


# lcplen fuer p = u[i..m] und q = v[j..n]
def lcplen(p, q)

  length = 0

  # Laenge des kuerzeren substrings
  x = min(p.len, q.len)

  (0..x).each do |i|

    # iteriere so lange bis missmatch
    if u[i] != v[i]

      break
    end

    length += 1
  end

  # gebe Laenge zurueck
  return length
end


def outsense_edist()

  front[0][0] = lcplen(m, n)
  d = 0

  # while front(m − n, d) = n
  while front[m-n][d] != n
    d+=1
  end

end


# get certain front value
def outsense_next_front(front, h, d, u, v, m, n)

  l = max(front[h-1][d-1],
          front[h+1][d-1] + 1,
          front[h-1][d] + 1)

  return (l + lcplen(u[(l+1)...m], v[(h+l+1)...n]))
end


def main

  m = u.len
  n = v.len

  front = Hash.new(m+n) {
    Array.new
  }

  front[m-n][0] = -1

end
