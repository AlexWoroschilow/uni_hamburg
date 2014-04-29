def structure_count(i, j, l)
  c=0
  if i < j
    c=1
    if i+1 < j-1
      c = c + structure_count(i+1, j-1, l)
    end
    if i+1 < j
      c = c + structure_count(i+1, j, l)
    end
    if i < j-1
      c = c + structure_count(i, j-1, l)
    end
    x = (i+2)
    y = (j-1)
    if (y-x) >= l
      (x..y).each do |k|
        c = c + structure_count(i, k-1, l)
        c = c + structure_count(k, j, l)
      end
    end
  end
  return c
end

(0..16).each do |n|
  puts "n: #{n}, S(n): #{structure_count(1, n, 1)}"
end


