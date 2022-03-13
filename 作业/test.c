#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>

//***************************************************************************
//1.多组输入，输出n行的X形图案

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j < n; j++)
			{
				if ((i == j) || (i + j == n - 1))
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}

//********************************************************************
//2.评委打分：输入7个成绩(0-100)，去掉一个最高分，去掉一个最低分，输出平均分,输出结果精确到小数点后两位

int main()
{
	int i = 0;
	int score = 0;//每次输入的成绩
	int max = 0;
	int min = 100;
	int sum = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &score);
		sum += score;
		if (score > max)
			max = score;
		if (score < min)
			min = score;
	}
	sum = sum - max - min;
	printf("%.2f\n", sum/5.0);
	return 0;
}

//******************************************************************
//3.输入年份和月份，输出相应的天数

int main()
{
	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year = 0;
	int month = 0;
	while (scanf("%d %d", &year, &month) != EOF)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if(month == 2)
			printf("%d\n", arr[month] + 1);
		}
		else
			printf("%d\n", arr[month]);
	}
	return 0;
}


//************************************************************************************
//输入一组有序排列的数字(1-50)，插入一个数，输出重新排序后的数字

int main()
{
	int n = 0;
	int i = 0;
	int arr[51];
	int m = 0;//插入的数字
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for (i = n-1; i >= 0; i--)
	{
		if (arr[i] > m)
		{
			arr[i + 1] = arr[i];
		}
		if (arr[i] <= m)
		{
			break;
		}
		
	}
	arr[i + 1] = m;
	for (i = 0; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


//***************************************************************************************
//模拟实现atoi函数：将字符串转化成数字

enum STATE
{
	INVALID,
	VALID
};

enum STATE state = INVALID;

int my_atoi(const char* p)
{
	//p为空指针，非法转化
	if (p == NULL)
	{
		return 0;
	}
	//空字符串，非法转化
	if (*p == '\0')
	{
		return 0;
	}
	//前面有空格，跳过空格
	while (isspace(*p))
	{
		p++;
	}
	//判断数字正负
	int flag = 1;
	if (*p == '-')
	{
		flag = -1;
		p++;
	}
	//数字的转化
	long long n = 0; //防止数字过大
	while (isdigit(*p))
	{
		n = n * 10 + flag * (*p - '0');
		//判断数字是否超出整型的表示范围
		if (n > INT_MAX || n < INT_MIN)
		{
			return 0;
		}
		p++;
	}
	state = VALID;
	return (int)n;
	
}

int main()
{
	const char* p = "    -125748a";
	int ret = my_atoi(p);
	//判断是合法转化还是非法转化
	if (state == INVALID)
	{
		printf("非法的转化：");
	}
	else
	{
		printf("合法的转化：");
	}

	printf("%d\n", ret);

	return 0;
}


//****************************************************************
//有一组数字中有两个数字值出现一次，其他数字都出现两次，找出这两个数并打印
//思路：将所有数字异或， 相同两个数字异或为0，最后结果就是要找的两个数异或的结果
//找出结果中哪一位二进制为1，按这一位进行将所有数字进行分组，两组分别异或

void Find(int arr[], int sz, int* px, int* py)
{
	//1.先将所有数字异或
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//2.找出ret中哪一位为1
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
		}
	}
	//3.分两组分别异或
	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	*px = num1;
	*py = num2;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int y = 0;
	Find(arr, sz, &x, &y);
	printf("%d %d\n", x, y);
	return 0;
}


//*********************************************************************************
//写一个宏，可以将一个整数的二进制位的奇数位和偶数位互换
//思路：将这个数按位与10101010101010101010101010101010，得到二进制的偶数位
//      将这个数按位与01010101010101010101010101010101，得到二进制的奇数位
//再将偶数位右移一位，奇数位左移一位，再相加就得到最后结果

#define SWAP(num) ((num&0xaaaaaaaa)>>1)+((num&0x55555555)<<1)

int main()
{
	int a = 10;
	printf("%d\n", SWAP(a));
	return 0;
}


//********************************************************************************
//写一个宏，计算结构体中某变量相对于首地址的偏移

#include<stddef.h>

struct S
{
	int a;
	short b;
	int c;
	char d;
};

//将0强转为结构体指针，成员的地址就是偏移量
#define OFFSETOF(struct_name,mem_name)  (int)&(((struct_name*)0)->mem_name)

int main()
{
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, b));
	printf("%d\n", OFFSETOF(struct S, c));
	printf("%d\n", OFFSETOF(struct S, d));
	return 0;
}