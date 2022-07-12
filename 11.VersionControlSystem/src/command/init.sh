#!/bin/bash

dir="$(pwd)"
[ -d "$dir/.kud" ] && { echo "Error: This directory is already a repository"; exit 1; }
mkdir -p "$dir/.kud"
mkdir -p "$dir/.kud/refs"
mkdir -p "$dir/.kud/refs/tags"
mkdir -p "$dir/.kud/snapshots"
exit 0