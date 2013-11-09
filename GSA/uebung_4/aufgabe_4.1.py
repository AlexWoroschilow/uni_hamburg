#! /usr/bin/env python2.7

import sys, math, getopt, numpy, string

class Substring:
    
    substring = None
    substring_pos = None
    substring_len = None
    
    def __init__(self, substring):
        self.substring = substring
        self.substring_len = len(substring) 
        self.substring_pos = 0
        
    def next (self):
        if self.substring_len > self.substring_pos :
            result = self.substring[self.substring_pos]
            self.substring_pos = self.substring_pos + 1
            return result
        return None
    
    def isEmpty (self):
        return self.substring == None

    def toString (self):
        return self.substring


class Sequenz:

    sequenz = None
    sequenz_len = None
    sequenz_pos = None
        
    def __init__(self, sequenz):
        self.sequenz = sequenz
        self.sequenz_len = len(sequenz)
        self.sequenz_pos = 0

    def substring(self, len):
        if self.sequenz_len >= self.sequenz_pos + len: 
            substring = self.sequenz[self.sequenz_pos:self.sequenz_pos+len]
            self.sequenz_pos = self.sequenz_pos + len
            return Substring(substring)
        return None 

def main(argv):
    
    k = 3
    
    # mc (aba, baa) = 1 
    # mc (aab, baa) = 1 
    # mc (aba, aab) = 1 
    # mc (aaa, baa) = 2 
    # mc (aab, aab) = 3 
    # mc (aba, aba) = 3 
    # mc (aaa, aab) = 2 
    # mc (aab, aba) = 1 
    # mc (aaa, aba) = 2 
    sequenz_1 = Sequenz ('abaaababaaaaaababaaaaaabaaa')
    sequenz_2 = Sequenz ('baabaaaabbaaaababaaababaaba')

    # Laufzeit ist O(n^2)
    while True :
        match_count = 0
        substring_1 = sequenz_1.substring(k)
        substring_2 = sequenz_2.substring(k)
        if substring_1 == None or substring_2 == None:
            break
        while True :
            char_1 = substring_1.next()
            char_2 = substring_2.next()
            if char_1 == None or char_2 == None :
                break
            if char_1 == char_2 : 
                match_count = match_count + 1
        print("mc (%s, %s) = %d " % (substring_1.toString(), substring_2.toString(), match_count))
        



if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

