#! /usr/bin/env python2.7

import sys, math, getopt, numpy

class Loesung:
    count = None
    matrix = None
    
    def __init__(self):
        self.count = 0 
    
    def getCount (self):
        return self.count 

    def aligns (self, i, j):
        self.count +=1
        result = 1
        if i <= 15 and j <= 15:
            if i != 0 and j != 0 :
                result = self.aligns(i-1, j) + self.aligns(i, j-1) + self.aligns(i-1, j-1)
            return result
        return None

    def alignsMatrix (self, i, j):
#         matrix = [[0 for x in xrange(i+1)] for x in xrange(j+1)]
                    
        return None


def main(argv):

    arg1 = None
    arg2 = None
    
    if len(argv) == 2 :
         
        arg1 = int(argv[0])
        arg2 = int(argv[1])
    
        loesung = Loesung()
        result = loesung.aligns(arg1, arg2)
        count = loesung.getCount()
        
        if result != None :
            print arg1, arg2, result, "(" + str(count) + " calls)"
            return(0)

    print("Falshe eingabe!")
    
    if arg1 == None or arg2 == None :
        print("Bitte, geben Sie zwei Zahlen ein!")
        return(0)
    
    print("i="+str(arg1)+" j="+str(arg2))
    return(0)
    

        
sys.argv[1]
sys.argv[2]
 
if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
    
    