#!/bin/bash

if [ ! -e build ]; then 
    mkdir build
fi
cd build
cmake .. -G "Unix Makefiles"
cmake --build .
cd ../bin
echo

for filename in $(ls *); do
    if [[ -x "$filename" ]; then
        echo ------------------------------------------
        echo "         Running" $filename
        echo ------------------------------------------
        ./$filename
    fi
done
cd ..