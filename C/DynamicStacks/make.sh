#!/bin/bash
extC=".c"
execFile=$1
cFile=$1$extC

gcc ~/College-Code/C/DynamicStacks/src/$cFile -o $execFile
mv ~/College-Code/C/DynamicStacks/$execFile ~/College-Code/C/DynamicStacks/output
cd ~/College-Code/C/DynamicStacks/output
./$1
cd ..
