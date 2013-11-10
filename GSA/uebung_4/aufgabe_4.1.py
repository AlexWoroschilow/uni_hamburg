#! /usr/bin/env python2.7

import sys, getopt, string, difflib



class Diff: 
    substring_1 = None
    substring_2 = None
    
    def __init__(self, substring_1, substring_2):
        self.substring_1 = substring_1
        self.substring_2 = substring_2
        
    def match (self):
        match_count = 0
        char_1 = self.substring_1.next(True)
        char_2 = self.substring_2.next(True)
        while char_1 != None or char_2 != None :
            if char_1 == char_2 : 
                match_count = match_count + 1
            char_1 = self.substring_1.next()
            char_2 = self.substring_2.next()
        return match_count
    

class Substring:
    
    substring = None
    substring_pos = None
    substring_len = None
    
    def __init__(self, substring):
        self.substring = substring
        self.substring_len = len(substring) 
        self.substring_pos = 0
        
    def next (self, test = False):
        if test : 
            self.substring_pos = 0
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
        if self.sequenz_pos <= self.sequenz_len - len: 
            substring = self.sequenz[self.sequenz_pos:self.sequenz_pos+len]
            self.sequenz_pos = self.sequenz_pos + 1
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
    
    seq_1 = 'aaaba'
    seq_2 = 'baaba'
    
    
    sequenz_1 = Sequenz (seq_1)
    substring_1 = sequenz_1.substring(k)
    while substring_1 != None :
        sequenz_2 = Sequenz (seq_2)
        substring_2 = sequenz_2.substring(k)
        while substring_2 != None :
            diff = Diff(substring_1, substring_2)
            print (substring_1.toString(), substring_2.toString(), diff.match())
            substring_2 = sequenz_2.substring(k)
        substring_1 = sequenz_1.substring(k)

#     
#     i = 0
#     matrix = list()
#     for char_1 in seq_1 :
#         j = 0
#         matrix_1 = list()
#         for char_2 in seq_2 :
#             if char_1 == char_2 :
#                 matrix_1.insert(j, 0)
#             else :
#                 matrix_1.insert(j, 1)
#             j = j + 1
#         matrix.insert(i, matrix_1)
#         i = i + 1
#     for test in matrix :
#         print(test)
        
        


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))