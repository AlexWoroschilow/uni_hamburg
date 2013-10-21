#! /bin/sh

echo ">> Aufgabe 1.3"
echo ">> Anfang von ychrIII.fna: "
echo -e "`head "./ychrIII.fna" | grep -v '>' | head -c 123 | tr -d "[:space:]" | fold --width=60 | tr "[:space:]" "\n"`"