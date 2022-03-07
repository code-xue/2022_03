#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//***************************************************************************
//1.�������룬���n�е�X��ͼ��

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
//2.��ί��֣�����7���ɼ�(0-100)��ȥ��һ����߷֣�ȥ��һ����ͷ֣����ƽ����,��������ȷ��С�������λ

int main()
{
	int i = 0;
	int score = 0;//ÿ������ĳɼ�
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
//3.������ݺ��·ݣ������Ӧ������

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
//����һ���������е�����(1-50)������һ�����������������������

int main()
{
	int n = 0;
	int i = 0;
	int arr[51];
	int m = 0;//���������
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