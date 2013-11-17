#! /usr/bin/env python2.7

import sys, getopt, string

from alignment.alignment import Alignment

    


def main(argv):
    
    seq1 = "acgtagatatatagat";
    seq2 = "agaaagaggtaagaggga";
    alg = "R7I2R2D1R3I1R3"; 
    
    alignment = Alignment(seq1, seq2, alg)
    
    alignment2 = alignment.alignment_new()
    print alignment2.alignment_show()

    alignment.alignment_add_insertion(5)
    alignment.alignment_add_insertion(5)
    alignment.alignment_add_deletion(6)
    alignment.alignment_add_replacement(22)    
    print alignment.alignment_show()




if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))