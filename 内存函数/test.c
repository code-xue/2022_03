#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//*******************************************************************
//memcpy�������ڴ濽������
//void * memcpy ( void * destination, const void * source, size_t num );
//num���ֽ�������

void* my_memcpy(void* dest, const void* sce, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)sce;
		((char*)dest)++;
		((char*)sce)++;
	}
	return ret;
}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1,20);
	return 0;
}

//***********************************************************************
//memmove��������һ���ڴ��е����ݿ�������һ���ڴ���

void* my_memmove(void* dest, const void* sce, size_t num)
{
	void* ret = dest;
	//��ǰ��󿽱�
	if (sce > dest)
	{
		while (num--)
		{
			*(char*)dest = *(char*)sce;
			((char*)dest)++;
			((char*)sce)++;
		}
		
	}
	else
		//�Ӻ���ǰ����
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)sce + num);
		}
	}
	return ret;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr, arr + 2, 20);
	return 0;
}

//**********************************************************************************
//memcmp�������Ƚ������ڴ��е�ֵ

int main()
{
	float arr1[10] = { 1.0,2.0,3.0,4.0,5.0 };
	float arr2[10] = { 1.0,3.0,5.0 };
	int ret = memcmp(arr1, arr2, 6);
	printf("%d\n", ret);
	return 0;
}

//*****************************************************************************
//memset�����������ڴ��д洢��ֵ

int main()
{
	int arr[10] = { 0 };
	memset(arr, 1, 10);
	return 0;
}
