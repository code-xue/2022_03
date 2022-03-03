#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//*******************************************************************
//memcpy函数：内存拷贝函数
//void * memcpy ( void * destination, const void * source, size_t num );
//num按字节数计算

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
//memmove函数：将一块内存中的数据拷贝到领一块内存中

void* my_memmove(void* dest, const void* sce, size_t num)
{
	void* ret = dest;
	//从前向后拷贝
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
		//从后向前拷贝
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
//memcmp函数：比较两块内存中的值

int main()
{
	float arr1[10] = { 1.0,2.0,3.0,4.0,5.0 };
	float arr2[10] = { 1.0,3.0,5.0 };
	int ret = memcmp(arr1, arr2, 6);
	printf("%d\n", ret);
	return 0;
}

//*****************************************************************************
//memset函数：设置内存中存储的值

int main()
{
	int arr[10] = { 0 };
	memset(arr, 1, 10);
	return 0;
}
