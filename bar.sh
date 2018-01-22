#!/bin/bash

i=0
index=0
str=''
arr=('-' '\' '|' '/')
while [ $i -le 100 ]
do 
	str=${str}
	str+='#'
	printf "%-100s[%d%%][%s]\r" "$str" "$i" "${arr[$index]}"
	let i++
	let index++
	let index%=4
	sleep 0.1
done 

#printf "" "" "" #是个命令
