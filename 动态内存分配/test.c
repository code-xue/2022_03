#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//********************************************************************
//malloc函数：开辟一定字节的内存空间，不会进行初始化
//void* malloc (size_t size);

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	//开辟40个字节的空间
	free(p);
	p = NULL;
	return 0;
}

//***************************************************************************
//calloc函数：开辟一定字节的内存空间，初始化为0
//void* calloc (size_t num, size_t size);

int main()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		perror("main");
		return;
	}
	free(p);
	p = NULL;
	return 0;
}

//**************************************************************************
//realloc函数：修改之前开辟出的内存空间大小
//void* realloc (void* ptr, size_t size);

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		perror("main");
		return;
	}
	//开辟40个字节的空间
	int* ptr = (int*)realloc(p, 100);
	//注意要先用一个临时指针接受realloc的返回结果，避免出现p被改为空指针的情况
	if (ptr != NULL)
	{
		p = ptr;
	}
	free(p);
	p = NULL;
	return 0;
}

//使用动态内存分配时常见的错误：
//1.对NULL的解引用操作
//2.对动态开辟空间的越界访问
//3.使用free释放非动态开辟空间
//4.使用free释放动态开辟空间的一部分
//5.对同一块动态开辟的空间多次释放
//6.动态开辟的空间忘记释放，造成内存泄露