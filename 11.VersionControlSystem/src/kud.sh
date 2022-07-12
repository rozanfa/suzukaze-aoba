#!/bin/bash

command=$1

[ "$command" == "" ] && { echo "Usage: $0 <command>"; exit 1; }

reldir="$( dirname -- "$0"; )";
$reldir/src/command/$command.sh ""${@:2}""
