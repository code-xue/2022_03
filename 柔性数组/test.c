#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct S
{
	int i;
	int arr[];//柔性数组，可根据需求更改其所占内存大小
	//有两种定义方法：arr[]或arr[0], 但不一定每个编译器都支持
};

//柔性数组的特点：
//1.结构中的柔性数组成员前面必须有一个其他类型的成员
//2.使用sizeof返回的结构大小不包括柔性数组的大小
//2.使用malloc函数分配空间时分配的空间大小不能小于结构体的大小

int main()
{
	//为柔性数组开辟10个整型大小的空间
	struct S* p = (struct S*)malloc(sizeof(int) + 10 * sizeof(int));
	p->i = 10;
	int x = 0;
	for (x = 0; x < 10; x++)
	{
		p->arr[x] = x;
	}
	free(p);
	p = NULL;
	return 0;
}