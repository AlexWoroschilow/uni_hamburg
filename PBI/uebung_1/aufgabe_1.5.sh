#! /bin/sh

echo ">> Aufgabe 1.5"

FILE="$HOME/.tcshrc"

echo -e "Remove file: ${FILE} `rm -f --force ${FILE}`"
echo -e "Create new file: ${FILE} `touch ${FILE}`"

echo -e "alias rm 'rm -i' >> ${FILE} `echo \"alias rm 'rm -i'\" >> ${FILE}`"
echo -e "alias cp 'cp -i' >> ${FILE} `echo \"alias cp 'cp -i'\" >> ${FILE}`"
echo -e "alias mw 'mw -i' >> ${FILE} `echo \"alias mw 'mw -i'\" >> ${FILE}`"
echo -e "setenv PATH $HOME/bin:$PATH >> ${FILE} `echo \"setenv PATH $HOME/bin:$PATH\" >> ${FILE}`"