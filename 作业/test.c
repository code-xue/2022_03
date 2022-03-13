#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>

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


//***************************************************************************************
//ģ��ʵ��atoi���������ַ���ת��������

enum STATE
{
	INVALID,
	VALID
};

enum STATE state = INVALID;

int my_atoi(const char* p)
{
	//pΪ��ָ�룬�Ƿ�ת��
	if (p == NULL)
	{
		return 0;
	}
	//���ַ������Ƿ�ת��
	if (*p == '\0')
	{
		return 0;
	}
	//ǰ���пո������ո�
	while (isspace(*p))
	{
		p++;
	}
	//�ж���������
	int flag = 1;
	if (*p == '-')
	{
		flag = -1;
		p++;
	}
	//���ֵ�ת��
	long long n = 0; //��ֹ���ֹ���
	while (isdigit(*p))
	{
		n = n * 10 + flag * (*p - '0');
		//�ж������Ƿ񳬳����͵ı�ʾ��Χ
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
	//�ж��ǺϷ�ת�����ǷǷ�ת��
	if (state == INVALID)
	{
		printf("�Ƿ���ת����");
	}
	else
	{
		printf("�Ϸ���ת����");
	}

	printf("%d\n", ret);

	return 0;
}


//****************************************************************
//��һ������������������ֵ����һ�Σ��������ֶ��������Σ��ҳ�������������ӡ
//˼·��������������� ��ͬ�����������Ϊ0�����������Ҫ�ҵ����������Ľ��
//�ҳ��������һλ������Ϊ1������һλ���н��������ֽ��з��飬����ֱ����

void Find(int arr[], int sz, int* px, int* py)
{
	//1.�Ƚ������������
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//2.�ҳ�ret����һλΪ1
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
		}
	}
	//3.������ֱ����
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
//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ����
//˼·�����������λ��10101010101010101010101010101010���õ������Ƶ�ż��λ
//      ���������λ��01010101010101010101010101010101���õ������Ƶ�����λ
//�ٽ�ż��λ����һλ������λ����һλ������Ӿ͵õ������

#define SWAP(num) ((num&0xaaaaaaaa)>>1)+((num&0x55555555)<<1)

int main()
{
	int a = 10;
	printf("%d\n", SWAP(a));
	return 0;
}


//********************************************************************************
//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ��

#include<stddef.h>

struct S
{
	int a;
	short b;
	int c;
	char d;
};

//��0ǿתΪ�ṹ��ָ�룬��Ա�ĵ�ַ����ƫ����
#define OFFSETOF(struct_name,mem_name)  (int)&(((struct_name*)0)->mem_name)

int main()
{
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, b));
	printf("%d\n", OFFSETOF(struct S, c));
	printf("%d\n", OFFSETOF(struct S, d));
	return 0;
}