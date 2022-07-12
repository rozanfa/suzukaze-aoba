#!/bin/bash

dir=$(pwd)
[ ! -d "$dir/.kud" ] && { echo "Error: This directory is not a repository"; exit 1; }

vid="$1"

[ $vid == "" ] && { echo "Usage: kud head <version-id>"; exit 1; }
[ ! -d "$dir/.kud/snapshots/$vid" ] && { echo "Error: Snapshot $vid does not exist"; exit 1; }

find -mindepth 1 -not -regex "^\./\.kud.*" -delete;

rsync --exclude ".commit" -a "$dir/.kud/snapshots/$vid/" "$dir/" || { echo "Error: rsync not found. Please install rsync package before using this version control system"; exit 1; }