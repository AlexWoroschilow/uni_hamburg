#! /usr/bin/env python2.7

import sys
from array import array


class Edit:
    
    k = None
    o = None
     
    def __init__(self, operator, key):
        self.k = key
        self.o = operator
        
    def getKey (self): 
        return self.k
    
    def check(self, o): 
        return self.o == o
    
    def getOperator (self): 
        return self.o


class Parser:
    
    k = ''
    p = None
    o = None
    
    def __init__(self):
        self.p = 0
    
    def next (self, string):
        if len(string) > self.p :
            temp = string[self.p]
            if temp in list('cir') :
                self.o = temp 
                self.p += 1
                self.k = ''
                for i in range(self.p, len(string)):
                    temp = string[i]
                    if temp in list('cir') :
                        self.p = i
                        break;
                    self.k = self.k + string[i]
                return Edit(self.o, int(self.k))
        return None


class Alignment:
    
    pos1 = None
    pos2 = None
    parser = None

    def __init__(self):
        self.parser = Parser()
    
    def test (self, seq1, seq2, alignment):
        sequenz1 = seq1
        sequenz2 = list(seq2)
        if len(seq2) > len(seq1) :
            sequenz1 = seq2
            sequenz2 = list(seq1)
        edit = self.parser.next(alignment)
        while edit :
            if edit.check('i') :
                sequenz2.insert(edit.getKey(), sequenz1[edit.getKey()])
            elif edit.check('c') :
                sequenz2[edit.getKey()] = sequenz1[edit.getKey()]
            elif edit.check('r') :
                sequenz2.pop(edit.getKey())
            edit = self.parser.next(alignment)
        return ''.join(sequenz2)




def main(argv):
    
    seq1 = "acgtagatatagagat"
    seq2 = "acgaagaggtaagagggt"
    
    alg = "c3i7i8r11i15c16"

    print (Alignment()).test(seq1, seq2, alg)
    
    

if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))