#!/bin/bash
cd /img
mkdir -p result
find . -maxdepth 1 -name '*bmp' | xargs -n 1 -P 8 -I \{\} convert \{\} -liquid-rescale 50% result/\{\}
