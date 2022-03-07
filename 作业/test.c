#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

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