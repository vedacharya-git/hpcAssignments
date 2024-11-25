#! /bin/bash

# Check if the path name is provided as an argument
if [ -z "$1" ]; then
	echo "Usage: $0 <path>"
	exit 1
fi

# Create the directories using the provided path name
mkdir -p "$1"

# Output success message
echo "Directories created successfully for path: $1"
