#! /usr/bin/env python2.7

import sys, math, getopt, numpy, string



def edist (string1, string2):
    
    n = len(string1)
    m = len(string2)
    
    matrix = [[0 for x in xrange(n+1)] for x in xrange(m+1)]
    
    matrix[0][0] = 0

    for j in range(1, n+1) :
        matrix[0][j] = matrix[0][j-1] + 1
         
    for i in range(1, m+1) :
        matrix[i][0] = matrix[i-1][0] + 1
         
        for j in range(1, n+1) :

            val1 = matrix[i-1][j] + 1
            val2 = matrix[i][j-1] + 1
            val3 = matrix[i-1][j-1] + cost(string2[i-1], string1[j-1])
            
            matrix[i][j] = min(val1, val2, val3) 
    
    return matrix  

def cost (char1, char2):
    if char1 == char2 :
        return 0
    return 1


def main(argv):
    


    seq_1 = 'aaaba'
    seq_2 = 'baaba'


    # Keine Ahnung wi es geht
    # ich habe keine ideen
    matrix = edist(seq_1, seq_2)

    for line in matrix :
        print  line


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

