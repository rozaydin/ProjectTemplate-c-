#!/bin/bash

[ ! -d "build" ] && mkdir build
cd build
cmake .. 
make 
make clangtidy
make coverage 
cd ..
sonar-scanner
echo "pipeline complete!"