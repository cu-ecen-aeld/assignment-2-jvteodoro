#!/bin/sh
filesdir=$1
searchstr=$2

if [ $# -ne 2 ]; then
    echo "Error required 2 arguments, given $#"
    exit 1
elif [ ! -d $1 ]; then
    echo "$filesdir is not a directory"
    exit 1 
fi
num_match=$(grep -r $1 -e $2 | wc -l)
num_files=$(ls $1 | wc -w)
echo "The number of files are $num_files and the number of matching lines are $num_match"

