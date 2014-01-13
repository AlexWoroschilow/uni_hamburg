#!/bin/sh

# script to check if the results of the Xdrop-extension is consistent
# with previously computed extensions
# Stefan Kurtz, January 2014

# addjust the name of the program to run

PROGRAM=./xdrop.rb

set -e -x

for xd in 10 15 20
do
  ${PROGRAM} hits 8 ${xd} testdb.fasta testquery.fasta 1 -2  > myoutput-${xd}.txt
  cmp myoutput-${xd}.txt results_${xd}.txt
  rm -f myoutput-${xd}.txt
done
