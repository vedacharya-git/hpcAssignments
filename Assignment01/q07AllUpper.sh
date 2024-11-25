#!/bin/bash

# Check if at least one filename is provided as an argument
if [ "$#" -eq 0 ]; then
	echo "Error: No filenames provided."
	echo "Usage: $0 <filename1> <filename2> ..."
	exit 1
fi

# Loop through all provided filenames
for file in "$@"; do
	# Check if the file exists in the current directory
	if [ -f "$file" ]; then
		# Convert the content of the file to uppoercase and overwrite the original file
		tr '[:lower:]' '[:upper:]' < "$file" > temp_file && mv temp_file "$file"
		echo "Converted '$file' to uppercase."
	else
		echo "Error: File '$file' does not exist in the current directory"
	fi
done
