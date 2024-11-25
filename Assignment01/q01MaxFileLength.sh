#!/bin/bash

# Check if the directory name is provided as an argument
if [ -z "$1" ]; then
	echo "Usage: $0 <directory>"
	exit 1
fi

# Check if the provided argument is a valid directory
if [ ! -d "$1" ]; then
	echo "Error: $1 is not a valid directory."
	exit 1
fi

# Find all files recursively, calculate their lengths, and find the maximum length
max_length=$(find "$1" -type f -exec wc -l {} + | awk '{print $1}' | sort -nr | head -n 1)

# Output the maximum file length
echo "The maximum file length is: $max_length"
