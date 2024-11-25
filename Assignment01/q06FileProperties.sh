#!/bin/bash

# Prompt the user to enter a file name
read -p "Enter the file name: " file_name

# Check if the file exists
if [ ! -e "$file_name" ]; then
	echo "Error: File '$file_name' does not exist."
	exit 1
fi

# Output the file properties
echo "Properties of '$file_name':"

# File type
if [ -d "$file_name" ]; then
	echo "Type: Directory"
elif [ -f "$file_name" ]; then
	echo "Type: Regular File"
elif [ -L "$file_name" ]; then
	echo "Type: Symbolic Link"
else
	echo "Type: Special File"
fi

# File size in bytes
file_size=$(stat -c %s "$file_name")
echo "Size: $file_size bytes"

# File permissions
file_permissions=$(stat -c %A "$file_name")
echo "Permissions: $file_permissions"

# File owner
file_owner=$(stat -c %U "$file_name")
echo "Owner: $file_owner"

# File group
file_group=$(stat -c %G "$file_name")
echo "Group: $file_group"

# Last modification date
mod_date=$(stat -c %y "$file_name")
echo "Last Modification Date: $mod_date"

# Number of links
num_links=$(stat -c %h "$file_name")
echo "Number of Links: $num_links"

# File inode
inode=$(stat -c %i "$file_name")
echo "Inode Number: $inode"
