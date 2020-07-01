#!/bin/sh

file_begin=0
file_end=90
simultaneous_number=5
file_number=$(($file_end-$file_begin+1))
wait_number=$(($file_number/$simultaneous_number))

for iw in `seq 0 $wait_number`
do
  temp_begin=$(($simultaneous_number*$iw))

  if [ $iw == $wait_number ] ; then
    temp_end=$file_end
  else
    temp_end=$(($temp_begin+$simultaneous_number-1))
  fi

  for i in `seq -f "test%04g.plt" $temp_begin $temp_end`
  do
    `gnuplot $i &`
  done

    `wait`
done
