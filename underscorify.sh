#!/bin/bash

# Check if the string is provided as an argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 \"Your string here\""
    exit 1
fi

# Convert the input string to lowercase, replace spaces with underscores, and append _ before .h
filename=$(echo "$1" | tr '[:upper:]' '[:lower:]' | sed 's/ /_/g').h

# problem link if present
problem_link="//$2"

# Create the file in the current directory
touch "$filename"

# Add the problem link to the file
echo $problem_link > $filename

# Notify the user
echo "File '$filename' created successfully."

git add $filename
