#!/bin/bash
mkdir convertidas

for img in *.png

do

   convert  "$img" -resize 5000x5000 -quality 90 "convertidas/$img"

done

cp formar_gift.sh  convertidas
