#!/bin/bash

black_list="test.sh ch_vrp_log.sh"

all_files=$(ls -1t *.*)

#echo $all_files
for file in $all_files
	do
#		echo $file
		found=0
		for black_file in $black_list
		do
#			echo $black_file
			if test "$file" = "$black_file" 
			then
				found=1
				break
			fi
		done

		if test $found -eq 0
		then
			echo "not found $file"
		else
			echo "found $file"
#			rm $file
		fi
done
