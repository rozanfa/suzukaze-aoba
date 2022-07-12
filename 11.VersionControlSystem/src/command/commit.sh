#!/bin/bash

dir=$(pwd)
[ ! -d "$dir/.kud" ] && { echo "Error: This directory is not a repository"; exit 1; }

n=1
while [[ -d "$dir/.kud/snapshots/$n" ]]; do
    n=$((n+1))
done

mkdir -p "$dir/.kud/snapshots/$n"

rsync --exclude ".kud" -a "$dir/" "$dir/.kud/snapshots/$n" || { echo "Error: rsync not found. Please install rsync package before using this version control system"; rmdir "$dir/.kud/snapshots/$n" ;exit 1; }
echo "version-id: $n" >> "$dir/.kud/snapshots/$n/.commit"
echo "user: $(whoami)" >> "$dir/.kud/snapshots/$n/.commit"
echo "time: $(date)" >> "$dir/.kud/snapshots/$n/.commit"
echo "message: $*" >> "$dir/.kud/snapshots/$n/.commit"