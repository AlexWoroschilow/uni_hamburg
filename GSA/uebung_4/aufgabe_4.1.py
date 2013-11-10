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
    
    def toString (self):
        return self.sequenz



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
    
    # O(k(n-k+1)^2) => O(kn^2)
    print ("\n Loesung 1 O(kn^2)")
    print ("\n\t Ausgabe:")
    
    sequenz_1 = Sequenz (seq_1)
    substring_1 = sequenz_1.substring(k)
    while substring_1 != None :
        sequenz_2 = Sequenz (seq_2)
        substring_2 = sequenz_2.substring(k)
        while substring_2 != None :
            diff = Diff(substring_1, substring_2)
            print "\t\t mc(%s, %s) = %d" % (substring_1.toString(), substring_2.toString(), diff.match())
            substring_2 = sequenz_2.substring(k)
        substring_1 = sequenz_1.substring(k)

     
    # O(n^2)
    print ("\n Loesung 2 O(n^2)")
    j = 0
    matrix = [[0 for x in xrange(len(seq_1))] for x in xrange(len(seq_2))] 
    for j in range (0, len(matrix)) :
        i = 0
        for i in range (0, len(matrix[i])) :
            if i == 0 or j == 0 :
                value = 0
                if seq_1[i] == seq_2[j] :
                    value = 1
                matrix[j][i] = value
            else :
                value =  matrix[j-1][i-1]
                if seq_1[i] == seq_2[j] :
                    value = value + 1
                matrix[j][i] = value

    print ("\n\t Matix")
    for line in matrix :
        print "\t\t", line


    print ("\n\t Ausgabe:")
    x = 0
    sequenz_1 = Sequenz (seq_1)
    substring_1 = sequenz_1.substring(k)
    while substring_1 != None :
        sequenz_2 = Sequenz (seq_2)
        y = 0
        substring_2 = sequenz_2.substring(k)
        while substring_2 != None :
            
            x_prev = x-1
            if x_prev < 0 :
                x_prev = None
            y_prev = y-1
            if y_prev < 0 :
                y_prev = None

            value = matrix[x + k - 1][y + k - 1]
            if x_prev != None and y_prev != None :
                value = value - matrix[x_prev][y_prev]
            
            print "\t\t mc(%s, %s) = %d" % (substring_2.toString(), substring_2.toString(), value )
            y = y + 1
            substring_2 = sequenz_2.substring(k)
        x = x + 1
        substring_1 = sequenz_1.substring(k)



if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))