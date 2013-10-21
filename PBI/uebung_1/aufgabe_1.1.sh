#! /bin/sh

echo ">> Aufgabe 1.1"
echo ">> Anzahl der Zeilen: "`cat "./ecoli.seq" "./swiss" | wc -l`
echo ">> Anzahl der Zeichen: "`cat "./ecoli.seq" "./swiss" | tr -d "\n" | wc -m`