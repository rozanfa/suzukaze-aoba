#!/bin/bash

dir=$(pwd)
[ ! -d "$dir/.kud" ] && { echo "Error: This directory is not a repository"; exit 1; }

[ ! -e "$dir/.kud/snapshots/*" ] || { echo "There is no commit yet"; exit 0; }

for i in $(ls -d "$dir/.kud/snapshots/"*); do
    cat "$i/.commit"
    echo "----------------------------------------------------"
done