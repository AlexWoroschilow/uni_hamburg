#! /usr/bin/env python2.7

import sys, math, getopt, numpy

class Loesung:
    
    countC = None
    countA = None
    matrix = None
    
    def __init__(self):
        self.countC = 0 
        self.countA = 0 
        self.matrix = []

    def calls (self):
        return self.countC

    def accesses (self):
        return self.countA 

    def alignsR (self, i, j):
        self.countC +=1
        result = 1
        if i <= 15 and j <= 15:
            if i != 0 and j != 0 :
                result = self.alignsR(i-1, j) + self.alignsR(i, j-1) + self.alignsR(i-1, j-1)
            return result
        return None

    def alignsM (self, n, m):
        if n <= 15 and m <= 15 :
            for i in range (0, n + 1) :
                self.matrix.append([])
                for j in range (0, m + 1) : 
                    if i == 0 or j == 0 :
                        self.matrix[i].append(1)
                    else :
                        self.countA += 1
                        self.matrix[i].append(self.matrix[i-1][j] + self.matrix[i][j-1] + self.matrix[i-1][j-1])
            return self.matrix[n][m]
        return None


def main(argv):

    arg1 = None
    arg2 = None

    if len(argv) == 2 :
        
        arg1 = int(argv[0])
        arg2 = int(argv[1])
        
        loesung = Loesung()
        
        resultM = loesung.alignsM(arg1, arg2)
        accesses = loesung.accesses()
        
        resultR = loesung.alignsR(arg1, arg2)
        calls = loesung.calls()
                
        if resultR != None and resultM != None:
            print arg1, arg2, resultM, "(" + str(accesses) + " accesses)"
            print arg1, arg2, resultR, "(" + str(calls) + " calls)"
            return(0)


    print("Falshe eingabe!")
    if arg1 == None or arg2 == None :
        print("Bitte, geben Sie zwei Zahlen ein!")
        return(0)
    print("i="+str(arg1)+" j="+str(arg2))
    return(0)



if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
    