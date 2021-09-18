#!/bin/bash
extJava=".java"
extClass=".class"
javaFile=$1$extJava
classFile=$1$extClass

javac ~/College-Code/Java/src/$javaFile
mv ~/College-Code/Java/src/$classFile ~/College-Code/Java/bin
cd ~/College-Code/Java/bin
java $1
cd ..
