#!/bin/bash

vid="$1"
tname="$2"


[ "$vid" == "" ] && { echo "Usage: kud tag <version-id> <tag-name>"; exit 1; }

[ "$tname" == "" ] && { echo "Usage: kud tag <version-id> <tag-name>"; exit 1; }

dir=$(pwd)

[ ! -d "$dir/.kud" ] && { echo "Error: This directory is not a repository"; exit 1; }

[ ! -d "$dir/.kud/snapshots/$vid" ] && { echo "Error: version id $vid doesn't exist"; echo "Usage: kud tag <version-id> <tag-name>"; exit 1; }

[ -e "$dir/.kud/refs/tags/$tname" ] && { echo "Error: tag $tname already exist"; exit 1; }

ln -s "$dir/.kud/snapshots/$vid" "$dir/.kud/refs/tags/$tname"

exit 0