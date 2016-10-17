#!/bin/sh

if [ "$#" -lt 2 ]; then
  echo "Usage: ./valgrind.sh [tool] [program]\ntools: memcheck callgrind"
  exit 1
fi

echo "Tool: $1"

if [ "$1" == "memcheck" ]; then
  shift
  valgrind --tool=memcheck --leak-check=full --show-reachable=yes --track-fds=yes --track-origins=yes --show-mismatched-frees=yes $@
fi

if [ "$1" == "callgrind" ]; then
  shift
  valgrind --tool=callgrind $@
fi
