#! /usr/bin/env python3

import sys, math

def getnext (list):
    if len(list) :
        return list.pop(0)
    return None


def reader (s, k):
    word = list()            
    char = getnext(s)
    while char != None :        
        if len(word) < k :
            word.append(char)
        else :
            word.pop(0)
            word.append(char)
            print word, len(word)                                    
        char = getnext(s)
    return 0


def main():
    
    k = 5
    s = 'gagtccgatggcgttggat'
    
    return reader(list(s), k)
        
 
if __name__ == "__main__":
    sys.exit(main())