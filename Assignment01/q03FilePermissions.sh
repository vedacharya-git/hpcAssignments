#!/bin/bash

# Check if two file names are provided as arguments
if [ "$#" -ne 2 ]; then
	echo "Usage: $0 <file1> <file2>"
	exit 1
fi

# Assign arguments to variables for clarity
file1="$1"
file2="$2"

# Check if the files exist
if [ ! -e "$file1" ]; then
	echo "Error: File '$file1' does not exist"
	exit 1
fi

if [ ! -e "$file2" ]; then
	echo "Error: File '$file2' does not exist"
	exit 1
fi

# Get the permissions of the files
perm1=$(stat -c "%A" "$file1")
perm2=$(stat -c "%A" "$file2")

# Check if the permissions are identical
if [ "$perm1" = "$perm2" ]; then
	echo "Common permissions: $perm1"
else
	echo "$file1 permissions: $perm1"
	echo "$file2 permissions: $perm2"
fi
