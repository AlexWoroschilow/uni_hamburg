#! /usr/bin/env python3

import sys, math

def block (s1, s2):
    if len(s1) == len(s2):
        distance = 0        
        for ch1, ch2 in zip (s1, s2):
            distance += abs(ch1 - ch2) 
        return distance
    return None

def euklid (s1, s2):
    if len(s1) == len(s2) :
        distance = 0
        for ch1, ch2 in zip (s1, s2):
            distance += math.pow((ch1 - ch2), 2)
        return math.sqrt(distance)
    return None  

def hamming (s1, s2):
    if len(s1) == len(s2) :
        distance = 0
        for ch1, ch2 in  zip(s1, s2):
            if ch1 != ch2:                 
                distance += 1
        return distance
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
    
    e1 = [1,4,3,9,1,2,5]
    e2 = [6,4,11,-9,-4,8,7]
    e3 = [5,1,4,3,9,1,2]
    
    print euklid(e1, e2)
    print euklid(e1, e3)
    print euklid(e2, e3)
     
    print block(e1, e2)
    print block(e1, e3)
    print block(e2, e3)
 
 
if __name__ == "__main__":
    sys.exit(main())