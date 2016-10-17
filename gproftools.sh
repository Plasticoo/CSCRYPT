#!/bin/sh

  if [ "$#" -lt 2 ]; then
    echo "Usage: ./gproftools.sh [tool] [program]\ntools: pprof heapcheck cpuprofiler"
    exit 1
  fi

echo "Tool: $1"

if [ "$1" == "pprof" ]; then
  shift
  HEAPPROFILE=/tmp/heapprof $@
fi

if [ "$1" == "heapcheck" ]; then
  shift
  HEAPCHECK=normal $@
fi

if [ "$1" == "cpuprofiler" ]; then
  shift
  CPUPROFILE=/tmp/prof.out $@
fi

