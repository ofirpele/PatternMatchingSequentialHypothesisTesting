#!/bin/csh

setenv LD_LIBRARY_PATH './libs':$LD_LIBRARY_PATH

./PatternMatching -P crowd/pattern.png -I crowd/im.png

./PatternMatching -P maras/pattern.png -I maras/im.png -M maras/mask.png

echo use ./hs --help to see full options
