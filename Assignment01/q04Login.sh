#!/bin/bash

# Check if at least one login name is provided
if [ "$#" -eq 0 ]; then
	echo "Error: No Login names provided"
	echo "Usage: $0 <login_name1> <login_name2> ..."
	exit 1
fi

# Iterate over each login name provided as an argument
for login_name in "$@"; do
	# Get the home directory for the current login name using the 'getent' command
	home_directory=$(getent passwd "$login_name" | cut -d: -f6)
	
	# Check if the login name is valid
	if [ -n "$home_directory" ]; then
		echo "Login name: $login_name, Home directory: $homedirectory"
	else
		echo "Error: Login name '$login_name' does not exist"
	fi
done
