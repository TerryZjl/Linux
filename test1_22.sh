#!/bin/bash

#1.求最大最小值
[ $# -eq 0 ] && {
	echo "Usage: $0 data1 ... datan"
	exit 1
}
max=$1
min=$1

for i in $@
do
	if [ $max -lt $i ];then
		max=$i
	fi
	if [ $max -gt $i ];then
		min=$i
	fi
done

echo "max=$max , min=$min"

#2.函数
#注意：在shell中的函数，函数在调用时被当作一个小脚本或者程序，所以调用函数时，不用带圆括号().
#注意：所有的代码快基本都不能为空。如果什么都不想做，可以只写一个冒号

function myfunc(){
	#函数体里绝对不能为空;如果什么都不想干，可以只写一个冒号
	#echo "my function"
	echo "$0" #$0在函数中没有被复用，仍然指向该脚本
	echo "$1" #其他几个$*都指向是函数的参数，被复用了
	echo "$2"
	echo "$3"
	echo "$@"
	echo "$#"
	echo "success" #通过echo返回值，可以从函数调用处接收 
	return 123     #return 只能返回整数
	
}

ret=`myfunc arg1 arg2 arg3` #函数调用
echo $ret #函数的返回信息
echo "$?" #函数的退出码


#3.用函数求最大最小值
function max_min(){
	local n=0
	max=$1 #函数默认定义的变量全局有效，若想本地有效看上面写法,加local
	min=$1
	for i in $@
	do
		if [ $i -lt $min ];then
			min=$i;
		fi
		if [ $i -gt $max ];then
			max=$i;
		fi
	done
}
max_min $@
echo "max=$max" 
echo "min=$min"

#4.fork炸弹
#.(){ . | . & }; .
#shell脚本是支持递归的
#此处的点是函数名
#|是管道，创建管道必定会创建子进程，这个函数是递归的fork，并且&把进程放到后台运行，我们只能给前台作业发信号，所以也终止不掉。


#5.shell脚本的调试
# 在头部加上-x,就可以显出输出语句的位置，代码头部不能有空行，如果有空行-x选项就不起效果。
#局部调试：调试 set -x  到 set +x 之间


#6.shell数组
#只支持一维数组
#给数组赋值必须以空格为分割符
arr=(3.14 'c' "hellowrold" 123)
#打印数组名代表打印第一个
echo $arr
#打印数组必须先用{}把数组名和[]结合起来
echo ${arr[2]}
#整体输出数组,只输出有效的
echo ${arr[@]}
echo ${arr[*]}
#打印数组个数，只统计有效的
echo ${#arr}
#数组赋值
arr[10]=15
#遍历数组,但是只能遍历到下标5
echo "-------------------------------------"
for ((i=0; i<${#arr[@]}; i++))
do 
	echo "${arr[$i]}"
done
#打印所有有效有效元素
echo "-------------------------------------"
for j in ${arr[@]}
do
	echo $j
done


#7.数组小实例
echo "-------------------------------------"
j=0
a=()
for i in {a..z}
do
	a[$j]=$i
	let j++
done
for j in ${a[@]}
do
	echo $j
done


