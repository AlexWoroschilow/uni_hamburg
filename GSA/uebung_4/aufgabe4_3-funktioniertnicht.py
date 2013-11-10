# GSA
# Aufgabe 4.3

import string
import sys


# hard-code sequences u and v
# later change this to make u,v Kommandozeilenparameters
u = "agtgtca"
v = "tgagcctgac"

# define the lengths of u and v
m = len(u)
n = len(v)


# define a fillDPtable function
def fillDPtable(x,y):


	for i in range(m+1):
		for j in range(n+1):
			print "i and j:"
			print i
			print j
			print
			
			
			if i == 0:
				if j == 0:
					return 0		# function works until here
					
				else:				# <--- problem is here? 
								# why does function break at the else statement?
					print 'else'
					for j in range(len(v)):
						return fillDPtable(0,j-1) + 1
				print 'something'
			else:
				if j == 0:
					return E(i-1,0) + 1
				else:
					for j in range(len(v)):
						if u[i] == v[j]:
							print u[i]
							print v[j]
							#return min(E(i-1,j) + 1, E(i,j-1) + 1, E(i-1,j-1))
						#else: 
						#	return min(E(i-1,j) + 1, E(i,j-1) + 1, E(i-1,j-1) + 1)



print 'edist='
print fillDPtable(m,n)
