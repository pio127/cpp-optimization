#!/bin/bash

if [ ! -e build ]; then 
    mkdir build
fi
cd build
cmake ..
cmake --build .
cd ../bin
echo

for filename in $(ls *exe); do
    echo ------------------------------------------
    echo "         Running" $filename
    echo ------------------------------------------
    ./$filename
done
cd ..