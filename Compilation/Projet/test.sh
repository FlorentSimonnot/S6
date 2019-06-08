#! /bin/bash 

rm -f report/*

echo "\n---------GOOD------------\n" >> report/report.log

for file in test/good/*; 
	do
	./compil  < $file >> report/report.log
	echo $file " : " $? >> report/report.log
	done

echo "\n---------BAD-------------\n" >> report/report.log

for file in test/bad/*; 
	do
	./compil  < $file >> report/report.log
	echo $file " : " $? >> report/report.log
	done

echo "See in report the file report.log !"
