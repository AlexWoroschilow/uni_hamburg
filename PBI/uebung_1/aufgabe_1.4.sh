#! /bin/sh

echo ">> Aufgabe 1.4"


echo -e ">> Alle Dataien mit std am Anfang und .h am Ende: \n `find /usr/include/ -name \*.h | grep --regexp="^\/.*\/std.*\.h$"`"
echo -e ">> Count: `find /usr/include/ -name \*.h | grep --regexp="^\/.*\/std.*\.h$" | wc -l` \n"
echo -e ">> Alle Dataien, die heute veraendert wurden: \n`find ~ -mtime 0` \n"
echo -e ">> Count: `find ~ -mtime 0 | wc -l` \n"
