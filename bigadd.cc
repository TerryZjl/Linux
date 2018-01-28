/*************************************************************************
	> File Name: bigadd.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Sat 27 Jan 2018 11:35:45 PM PST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

bool addnumber(char *num)
{
	int len = strlen(num);
	int i = 0;
	int sum = 0;
	int ntakeover = 1;
	int istrue = false;
	for(i = len-1;i>=0;i--)
	{
		sum = num[i]-'0' + ntakeover;

		if(sum >= 10)
		{
			if(i == 0)
			{
				istrue = true;
			}
			else
			{
				sum -= 10;
				num[i]  =  sum + '0';
			}
		}
		else
		{
			num[i] = sum + '0'; 		
			break;
		}
	}
	return istrue;
}
void printnumber(char* number)
{
	int len = strlen(number);
	int i = 0;
	for(i = 0;i<len;i++)
	{
		if(number[i] == '0')
			continue;
		cout<<number[i];
	}
	cout<<"  ";
}

void Printadd(int len)
{
	char *number = new char[len+1];
	memset(number,'0',len);
	number[len] = '\0';
	while(!addnumber(number))
	{
		printnumber(number);
	}
	cout<<endl;
	delete []number;
}
int main()
{
	Printadd(3);
	return 0;
}
