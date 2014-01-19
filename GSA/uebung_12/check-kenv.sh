#!/bin/sh

PROGRAM=./kenv.rb

TMPFILE=`mktemp TMP.XXXXXX` || exit 1
touch ${TMPFILE}
for protein in `cat proteins.txt`
do
  echo ${protein} >> ${TMPFILE}
  ${PROGRAM} ${protein} 4 22 >> ${TMPFILE}
done
cmp -s ${TMPFILE} proteins-envs.txt
if test $? -ne 0
then
  echo "$0: result is wrong: run \"diff ${TMPFILE} proteins-envs.txt\""
  exit 1
fi
rm -f ${TMPFILE}
