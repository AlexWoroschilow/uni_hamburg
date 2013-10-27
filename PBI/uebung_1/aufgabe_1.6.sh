#! /bin/sh

echo ">> Aufgabe 1.6"

FOLDER="./root"
SUBFOLDER="sub"
SUBFOLDERFILE="example"

echo -e "Remove test folder ${FOLDER} `rm -rf --force ${FOLDER}`"
echo -e "Create folder ${FOLDER} `mkdir -v ${FOLDER}`"
for i in 1 2 3 4 5 6 7 8 9 10
do
   echo "Create folder ${FOLDER}/${SUBFOLDER} `mkdir ${FOLDER}/${SUBFOLDER}$i`"
	for j in 1 2 3 4 5 6 7 8 9 10
	do
		echo "Create folder ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDER}$j `mkdir ${FOLDER}/${SUBFOLDER}$i$j`"				
	done
done

echo -e "`ls -rtla ${FOLDER}`"