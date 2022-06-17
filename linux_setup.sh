#!/bin/bash
mkdir build
mkdir build/release
mkdir build/debug
cd build/release
cmake -DCMAKE_BUILD_TYPE=Release ../../
cd ../debug
cmake -DCMAKE_BUILD_TYPE=Debug ../../
cd ../../