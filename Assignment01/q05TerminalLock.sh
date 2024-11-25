#!/bin/bash

# Function to disable BREAK and Control-D signals
trap '' 2 20

echo "Terminal Locking Script"

# Prompt user for a password
read -s -p "Enter password: " password
echo

# Prompt user to confirm password
read -s -p "Confirm password: " password_confirm
echo

# Check if password matches confirmation
if [ "$password" != "$password_confirm" ]; then
	echo "Error: Passwords do not match. Exiting."
	exit 1
fi

echo "Terminal Locked. Enter correct password to unlock"

# Infinite lock to keep terminal locked until password is entered
while true; do
	# Prompt the user to enter password
	read -s -p "Enter password to unlock: " unlock_password
	echo
	
	if [ "$unlock_password" = "$password" ]; then
		echo "Terminal unlocked"
		break
	else
		echo "Incorrect password"
	fi
done

# Re-enable BREAK and Control-D signals
trap 2 20
