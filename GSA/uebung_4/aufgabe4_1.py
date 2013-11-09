# GSA
# Aufgabe 4.1

import string
import sys

print 			#print empty line for aesthetics

k = 3			# choose a substring lenth

s1 = "aaaba"	# hard-code two strings, s1 and s2
s2 = "baaba"




def matchcount(x,y):
	# reset counter for matchcount to 0 every time the function is called
	counter = [0]
	for i in range(len(x)):
		if x[i] == y[i]:
			counter[0] +=1
		else:
			break
	print 'mc(' + sub1 + ', ' + sub2 + ') = ' + str(counter[0])



for i in range(len(s1)):
	try:
		s1[i+k-1]
		sub1 = s1[i : i + k]		# all substrings of length k of s1
		
		for j in range(len(s2)):	
			try:
				s2[j+k-1]
				sub2 = s2[j:j+k]	# for every combination of substrings

			except IndexError:		# break if j+k index is out of range
				break
				
			mc = matchcount(sub1,sub2)
			
	except IndexError:				# break if i+k index is out of range
		break	
	
print								# print empty line for aesthetics
