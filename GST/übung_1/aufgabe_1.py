#! /usr/bin/env python3

import sys
import aufgabe

def hamming (s1, s2):
    if len(s1) == len(s2) :
        i = 0
        for ch1, ch2 in  zip(s1, s2):
            if ch1 != ch2:                 
                i += 1
        return i
    return None


def main():
    
    s1 = 'acgatactag'
    s2 = 'aggtcattga'
    s3 = 'aggcattga'
    s4 = 'cgatactaga'
    
    print hamming (s1, s2)
    print hamming (s1, s3)
    print hamming (s1, s4)
    print hamming (s2, s3)
    print hamming (s2, s4)    
    print hamming (s3, s4)
     
 
if __name__ == "__main__":
    sys.exit(main())