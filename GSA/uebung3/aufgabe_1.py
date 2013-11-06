#! /usr/bin/env python2.7

import sys

class Edit:
    
    k = None
    e1 = None
    e2 = None
        
    def __init__(self, k, e1, e2):
        self.k = k
        self.e1 = e1
        self.e2 = e2
        
    def getKey (self):
        return self.k
    
    def getElement1(self): 
        return self.e1
    
    def getElement2(self): 
        return self.e2


class Parser:
    
    k = ''
    p = None
    o = None
    e1 = None
    e2 = None
    
    def __init__(self):
        self.p = 0
    
    def next (self, string):
        if len(string) > self.p :
            temp = string[self.p]
            if temp in list('0123456789') :
                self.k = ''
                for i in range(self.p, len(string)):
                    temp = string[i]
                    if temp in ('agct-') :
                        self.e1 = string[i]
                        self.e2 = string[i+1]
                        self.p = i+2
                        break;
                    self.k = self.k + string[i]
                return Edit(int(self.k), self.e1, self.e2)
        return None


class Alignment:
    
    parser = None
    sequenz = None
    aligment = None

    def __init__(self, sequenz, aligment):
        self.parser = Parser()
        self.sequenz = sequenz
        
        self.aligment = aligment
        
    def convertSequenz2ToSequenz1 (self):
        return self.sequenz
    
    def convertSequenz1ToSequenz2 (self):
        current = 0
        # man darf nicht im Python ein String als
        # ein Array aendern, deshalb benutzen wir hier list
        sequenz = list(self.sequenz) 
        edit = self.parser.next(self.aligment)
        # O(|alignment|)
        while edit :
            current = current + edit.getKey()
            e1 = edit.getElement1()
            e2 = edit.getElement2()
            if e2 == '-' :
                sequenz.insert(current, e1)
            elif e1 == '-' :
                sequenz.pop(current)
                current = current - 1
            else :
                sequenz[current] = e1
            edit = self.parser.next(self.aligment)
        return ''.join(sequenz)
    

def main(argv):
    
    # die Hauptidee ist, dass wir das Unterschied zwischen die Sequenzen beschreiben
    # und zwar so, als ob wir immer die kleinste Sequenz zur laengste Sequenz transformieren wollen
    # 
    # 
    # Probleme:
    #
    # 1. grosse Abstaende zwischen zwei Zeichen, die veraendert werden muessen
    # 
    #
    # Natuerlich ist es zu optimieren
    #
    # 1. wir koenen statt der decimalen Zahlen auch hexadezimalen Zahlen oder noch was besseres benutzen
    # 2. man kann auch Parser erleichtern
    # in diesem Fall konnte ich nicht mehr speichereffiziente Datenstruktur erfinden
    
     
    seq1 = "acgtagatatagagat"
    seq2 = "acgaagaggtaagagggt"
    alg = "3at4g-1g-3-t4g-2ga"

    # Hier brauchen wir nur unsere kurze Sequenz 
    # und auch das Unterschied zwischen den Sequenzen, das bedeutet, dass Datenstruktur sieht so aus:
    #    "acgtagatatagagat"      - kurze Sequenz
    #    "3at4g-1g-3-t4g-2ga"    - das Unterschied zwischen der Sequenzen
    #    3 - der Abstand von dem Anfang der Zeile
    #    a - das Zeichen aus der zweite Sequenz
    #    t - das Zeichen aus der zweite Sequenz
    #    4 - der Abstand von dem letzten veraenderten Zeichen
    #    g - das Zeichen aus der zweite Sequenz
    #    - - ein leeres Zeichen bedeutet entweder "insert" oder "remove"
    #    ... und so weiter
    #    
    #
    # Speicherplatzaufwand:
    #
    #    (|sequenz| * 4) + (Summe von i=0 bis i=|alignment|  8 + len(str(i+1 - i)) )
    # 
    # Redundanzen:
    #     keine
    #
    # Laufzeit:
    #    
    #    ohne Parser: O(|alignment|)
    #    
    #
    
    test1 = (Alignment(seq1, alg)).convertSequenz1ToSequenz2()
    test2 = (Alignment(seq1, alg)).convertSequenz2ToSequenz1() 


    print "Gleich(?):", test1 == seq2, ",", test1, seq2
    print "Gleich(?):", test2 == seq1, ",", test2, seq1
    


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))