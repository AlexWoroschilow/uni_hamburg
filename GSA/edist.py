#! /usr/bin/env python2.7

import sys, getopt, string, difflib


class Distance:

    matrix = None
        
    def __init__(self, seq1, seq2):
        n = len(seq1) + 1
        m = len(seq2) + 1
        
        self.matrix = [[0 for x in xrange(n)] for x in xrange(m)]
        
        self.matrix[0][0] = 0
        
        for i in range(1, n):
            self.matrix[0][i] = self.matrix[0][i-1] + 1
            
        for j in range(1, m):
            self.matrix[j][0] = self.matrix[j-1][0] + 1
            
            for i in range(1, n):
                
                var1 = self.matrix[j-1][i] + self.cost(seq2[j-1], None)
                var2 = self.matrix[j][i-1] + self.cost(None, seq1[i-1])
                var3 = self.matrix[j-1][i-1] + self.cost(seq1[i-1], seq2[j-1])
                
                self.matrix[j][i] = min(var1, var2, var3)
                
    def cost (self, char1, char2):
        if char1 != None and char2 != None:
            if char1 == char2 :
                return 0
            return 2
        return 1

    def getMatrix (self):
        return self.matrix
    
    def getEdist (self, x, y):
        if len(self.matrix) > y:
            if len(self.matrix[y]) > x :
                return self.matrix[y][x] 
        return None


def main(argv):
    
    
    distance = Distance ("stress", "rests");
    for line in distance.getMatrix() :
        print(line)
        
    print (distance.getEdist(5, 1))
    
         
    
    
    



if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))