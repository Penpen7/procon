#!/bin/bash
original_code=../t.cpp

for copy in a b c d e f;do
  cp $original_code $copy.cpp
done
