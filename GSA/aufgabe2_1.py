# GSA
# Aufgabe 2.1


# Nummer 1

import string

counter=[0]

def Aligns(m,n):
	counter[0] += 1
	if m > 15 or n > 15:
		return 'Error. Parameters must be less than or equal to 15.'
	else:
		if m ==0:
			return 1
		elif n ==0:
			return 1
		else:
			return Aligns(m-1,n) + Aligns(m,n-1) + Aligns(m-1,n-1)

# Ask for user input of m and n
x = int(raw_input('Choose m: '))
y = int(raw_input('Choose n: '))

a = Aligns(x,y)

# Either print answer or error message
if isinstance(a,int) == True:
	print x, y, a, '(', counter[0], 'calls)'
else:
	print a

		
print 
print


# Nummer 2	

#p = 15
#q = 11
#print p, q, Aligns(p,q), '(', counter[0], ' calls)'

# Wir sehen damit, dass
# Aligns(15,11) = 921406335 braucht 1382109596 Anrufe der Funktion Aligns. 




# Nummer 3


counter=[0]

def Alignstab(m,n):
#	if m > 15 or n > 15:
#		return 'Error. Parameters must be less than or equal to 15.'
#	else:
		Matrix = []
		for i in range(0,m+1):
			Matrix.append([])
			for j in range(0,n+1):
				if i == 0:
					x = 1
				elif j == 0:
					x = 1
				else:
					x = Matrix[i-1][j] + Matrix[i][j-1] + Matrix[i-1][j-1]
					# counter = Nummer Zugriffe auf die Matrix
					counter[0] += 3
				Matrix[i].append(x)
		return Matrix[m][n]


# Ask for user input of m and n
x = int(raw_input('Choose m: '))
y = int(raw_input('Choose n: '))

b = Alignstab(x,y)

# Either print answer or error message
#if isinstance(b,int) == True:
print x, y, b, '(', counter[0], 'accesses)'
#else:
#	print b

print
print



# Nummer 4

f = 15
g = 11
print 'Alignstab(15,11):'
print f, g, Alignstab(f,g), '(', counter[0], 'accesses)'

# Wir sehen damit, dass
# Aligns(15,11) = 921406335 braucht 522 Zugriffe auf die Matrix. 
