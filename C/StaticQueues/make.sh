#!/bin/bash
extC=".c"
cFile=$1$extC
execFile=$1

gcc ~/College-Code/C/Linked\ Lists/src/$cFile -o $execFile
mv ~/College-Code/C/$execFile ~/College-Code/C/output
cd ~/College-Code/C/output
./$1
cd ..
