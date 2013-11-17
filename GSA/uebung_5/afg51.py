#! /usr/bin/env python2.7

import sys, getopt, string

from alignment.cost import Einheitskost
from alignment.alignment import Alignment

    


def main(argv):
    
    seq1 = "acgtagatatatagat";
    seq2 = "agaaagaggtaagaggga";
    alg = "R7I2R2D1R3I1R3"; 
    
    alignment = Alignment(Einheitskost(), seq1, seq2, alg)
    
    print(">> Hier machen wir eine neue Alignment")
    alignment2 = alignment.alignment_new()
    print alignment2.alignment_show()
    
    print(">> 'alignment_show' macht nichts weil wir jetzt keine multiedit-Operationen haben")
    print(">> jetzt fuegen wir 5 insertion hinzu")
    alignment2.alignment_add_insertion(5)
    print alignment2.alignment_show()
    print(">> jetzt macht `alignment_show` was")
    
    print(">> hier berechnen wir Einheitskost: %d" % alignment.alignment_evalcost())
    
    print(">> hier das Alignment ausgeben\n")
    print alignment.alignment_show()

    print(">> hier fuegen wir insertion, deletion and replacement hinzu\n")
    alignment.alignment_add_insertion(5)
    alignment.alignment_add_deletion(6)
    alignment.alignment_add_replacement(22)    
    print(">> hier berechnen wir Einheitskost: %d" % alignment.alignment_evalcost())
    print(">> hier das Alignment ausgeben\n")
    print alignment.alignment_show()
    
    print(">> hier machen wir delete\n")
    alignment.alignment_delete()
    print(">> hier das Alignment ausgeben\n")
    print alignment.alignment_show()



if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))