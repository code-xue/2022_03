#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//*************************************************************
//结构体类型

//1.结构体自引用

struct Node
{
	int data;
	struct Node* next;
};
//或者写成
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//2.结构体初始化

struct S
{
	char c;
	int a;
	double d;
};

struct S2
{
	int b;
	struct S s;
	char ch;
};

int main()
{
	struct S2 s2 = { 1, {'x', 2, 3.5}, 'c' };
	printf("%d %c %d %lf %c", s2.b, s2.s.c, s2.s.a, s2.s.d, s2.ch);
	return 0;
}

//3.结构体的内存对齐
//对齐规则：
//1.第一个成员存放在与结构体变量偏移量为0的地址处
//2.其他成员变量存放在对齐数的整数倍的偏移量地址处
//对齐数：编译器默认的对齐数和该成员变量大小的较小值
//3.结构体的总大小为最大对齐数的整数倍
//4.结构体嵌套情况下，嵌套的结构体对齐到自己的最大对齐数的整数倍处
//结构体的整体大小就是所有对齐数的最大的整数倍（包括嵌套的结构体的最大对齐数）

struct S
{
	char c;
	int a;
	double d;
};
//结构体总大小为16个字节
//另外vs编译器的默认对齐数还可以通过#pragma pack();修改
//
//4.结构体传参

struct S
{
	char c;
	int a;
}s1;
//结构体直接传参
void print1(struct S s)
{
	printf("%d\n", s.a);
}
//结构体指针传参
void print2(struct S* ps)
{
	printf("%d\n", ps->a);
}

int main()
{
	s1.c = 'x';
	s1.a = 1;
	print1(s1);
	print2(&s1);
	return 0;
}
//尽量使用指针进行传参

//5.位段：节省内存空间

struct S
{
	int _a : 2;
	int _b : 3;
	int _c : 6;
};
//1.位段的成员必须是整型变量（包括char）
//2.成员后面有个:和数字，代表这个成员占几个bit位
//3.位段上的空间是根据需要以4个字节或1个字节来开辟的
//4.位段中存在很多不确定因素，不能跨平台，注重可移植性的程序应该避免使用位段

//**************************************************************************************
//enum:枚举类型

//1.定义

enum Color
{
	RED,//0
	GREEN,//1
	BLUE//2
};
//也可以定义时赋初值
enum Color
{
	RED = 5,//5
	GREEN = 8,//8
	BLUE//9
};

//2.使用
int main()
{
	enum Color c = BLUE;
	return 0;
}

//使用枚举类型的优点:
//1.增加代码的可读性和可维护性
//2.和#define定义的标识符相比枚举有类型检查，更加严谨
//3.防止了命名污染（封装）
//4.便于调试
//5.使用方便，一次可以定义多个常量