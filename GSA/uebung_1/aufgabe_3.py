# Aufgabe 1.3

import string

s = 'gagtccgatggcgttggattgagcgtgatcg'
print 'sequence: ' + s

comp = {
'a':'t',
't':'a',
'g':'c',
'c':'g'
}

revcomp = []
for i in s[::-1]:
	revcomp.append(comp[i])

reversecomp = ''.join(revcomp)
print 'reverse complement: ' + reversecomp
     
    
