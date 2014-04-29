#Input ist entweder ein einzelner Pairlist-String und die Länge
# 	-> pairlist2vienna {(1,2),(4,5)} 5
# 	-> Output ist dann der entsprechende Vienna-String
#Oder Input ist eine Text-Datei mit beliebig vielen Pairlist-Strings 
#und ihrer Länge
#	-> pairlist2vienna vienna2pairlist_output.txt
#	-> Output ist Text-Datei pairlist2vienna_output.txt mit den 
#	   entsprechenden Vienna-Strings

def p2v(plist)
	new = (plist.scan(/\d{1,2}/))
	i = 0
	while i < new.size-1 do
		$vienna[new[i].to_i-1] = "("
		$vienna[new[i+1].to_i-1] = ")"
		i += 2
	end
	$vienna.each_with_index do |char, j|
		if char == nil
			$vienna[j] = "."
		end
	end
end

def output()
	return $vienna.join("") + "\n"
end


begin
	file = IO.readlines(ARGV[0])
	filew = File.open("pairlist2vienna_output.txt", "w")
rescue
	$vienna = Array.new(ARGV[1].to_i)
	p2v ARGV[0]
	puts output
else
	for line in file 
		$vienna = Array.new((line.split('}')[-1]).to_i)
		p2v (line.scan(/\{.+\}/)).to_s
		filew.write(output)
	end
ensure
	filew.close unless filew == nil
end





