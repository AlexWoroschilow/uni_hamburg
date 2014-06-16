#!/bin/sh

if test $# -eq 0
then
  echo "$0 requires at least one argument, namely 1 and/or 2"
  exit 1
fi

# Skript to download two Ecoli genomes if not available yet.

for genome in $*
do
  if test ${genome} -eq 1
  then
    if test ! -f Ecoli_K12.fna
    then
      curl -o Ecoli_K12.fna ftp://ftp.ncbi.nih.gov/genomes/Bacteria/Escherichia_coli_K_12_substr__MG1655_uid57779/NC_000913.fna
    fi
  fi
  if test ${genome} -eq 2
  then
    if test ! -f Ecoli_O127_H6.fna
    then
      curl -o Ecoli_O127_H6.fna ftp://ftp.ncbi.nih.gov/genomes/Bacteria/Escherichia_coli_O127_H6_E2348_69_uid59343/NC_011601.fna
    fi
  fi
done
