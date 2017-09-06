#include <stdio.h> 
#include <time.h> 
#include <memory.h> 

int main(void)
{
	time_t t1;
	time_t t2;

	struct tm OldTime;
	struct tm NewTime;

	memset(&OldTime, 0x0, sizeof(OldTime));
	OldTime.tm_year = 110;// 2010 年表示为 2010 - 1900 = 110 
	OldTime.tm_mon = 12;
	OldTime.tm_mday = 6;

	memset(&NewTime, 0x0, sizeof(NewTime));
	NewTime.tm_year = 111;// 2011 年表示为 2011 - 1900 = 111 
	NewTime.tm_mon = 12;
	NewTime.tm_mday = 6;

	t1 = mktime(&NewTime); //2011-12-6 
	t2 = mktime(&OldTime); //2010-12-6 

	printf("%d", (t2 - t1) / (24 * 3600));
	return 0;

        printf("i = %d\n",i);
}
//结构体成员不可以赋值一个常量？？？看下面，形参无法赋给结构提成员
//int day(dddddd`int data1, int data2, int data3, int data4, int data5, int data6)
//{
//	time_t t1;
//	time_t t2;
//
//	struct tm OldTime;
//	struct tm NewTime;
//
//	memset(&OldTime, 0x0, sizeof(OldTime));
//	OldTime.tm_year = data1;// 2010 年表示为 2010 - 1900 = 110 
//	OldTime.tm_mon = data2;
//	OldTime.tm_mday = data3;
//
//	memset(&NewTime, 0x0, sizeof(NewTime));
//	NewTime.tm_year = data4;// 2011 年表示为 2011 - 1900 = 111 
//	NewTime.tm_mon = data5;
//	NewTime.tm_mday = data6;
//
//	t1 = mktime(&NewTime); //2011-12-6 
//	t2 = mktime(&OldTime); //2010-12-6 
//   
//	printf("%d\n",(t1 - t2) / (24 * 3600));
//	return ((t2 - t1) / (24 * 3600));
//}

