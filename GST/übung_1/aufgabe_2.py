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
            word.append(char)
            word.pop(0)
            print word, len(word)                
        
#         if len(word) == k:            
            
        char = getnext(s)


def main():
    
    k = 3
    s = list('gagtccgatggcgttggat')
    
    reader(s, k)
        
  
 
if __name__ == "__main__":
    sys.exit(main())