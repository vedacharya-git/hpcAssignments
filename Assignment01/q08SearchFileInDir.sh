#!/bin/bash

# Check if the first argument <filename> is provided
if [ -z "$1" ]; then
	echo "Usage: $0 <filename> [search directory]"
	exit 1
fi

# The filename to search for links
file_to_find="$1"

# Determine the starting directory for the search
if [ -z "$2" ]; then
	# If the second argument is not provided, use the current directory
	search_dir="."
else
	# use the directiry provided in the second argument
	search_dir="$2"
fi

# Get the inode number of the specified file
inode=$(ls -i "$file_to_find" | awk '{print $1}')

# Find and display all the files with the same inode number
echo "Searching for links to '$file_to_find' starting from '$search_dir'..."
find "$search_dir" -inum "$inode"
