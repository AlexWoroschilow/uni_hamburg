#! /usr/bin/env python2.7

import sys, math, getopt, numpy


class Helper:
    p = None
    
    def __init__(self):
        self.p = 0
    
    def getnext (self, string):
        if len(string) > self.p :
            result = string[self.p]
            self.p += 1
            return result
        return None


def loesung (s, k, n):
    word = list()
    hlp = Helper() 
    char = hlp.getnext(s)
    while char != None :
        if char not in n :
            if len(word) == k :
                word.pop(0)
                word.append(char)
                print word, len(word)                                    
            else :
                word.append(char)
        else :
            word = list()
        char = hlp.getnext(s) 

def main(argv):


    k = 5
    n = 'tn'
    s = 'atgcatgcggttcgatgcgaccaatgcgtgncgtgaaaccatgcggngggntgcgaacnaatgcgtgcg'
    
    loesung (s, k, n)


 
if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
    
    