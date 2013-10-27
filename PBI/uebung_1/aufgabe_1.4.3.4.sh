#! /bin/sh

echo ">> Aufgabe 1.4.(3/4)"

FOLDER="./root"
SUBFOLDER="sub"
SUBFOLDERFILE="example"

echo -e "Remove test folder ${FOLDER} `rm -rf --force ${FOLDER}`"
echo -e "Create folder ${FOLDER} `mkdir -v ${FOLDER}`"
for i in 1 2 3 4 5 6 7 8 9 10
do
   echo "Create folder ${FOLDER}/${SUBFOLDER} `mkdir -v ${FOLDER}/${SUBFOLDER}$i`"
	for j in 1 2 3 4 5 6 7 8 9 10
	do
		echo "Create file ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDERFILE}$j.txt `touch ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDERFILE}-first-$j.txt`"
		echo "Create folder ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDER}$j `mkdir -v ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDER}$j`"				
		echo "Create file ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDER}$j/${SUBFOLDERFILE}-first-$j.txt `touch ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDER}$j/${SUBFOLDERFILE}-second-$j.txt`"
		echo "Create file content ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDER}$j/${SUBFOLDERFILE}-first-$j.txt `echo UNIX >> ${FOLDER}/${SUBFOLDER}$i/${SUBFOLDER}$j/${SUBFOLDERFILE}-second-$j.txt`"
	done
done

# Teil 1.4 (3)
echo -e "Do chmod +xr ${FOLDER} `find ${FOLDER} -type d -exec chmod go=rx {} \;`"

# Teil 1.4 (4)
echo -e "Do chmod +xr ${FOLDER} `find ${FOLDER} -type f -name *.txt -exec grep -H \"U\" {} \;`"
