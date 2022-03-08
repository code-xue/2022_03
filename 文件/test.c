#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//文件分为程序文件和数据文件
//程序文件包括源程序文件（.c）、目标文件（.obj）、可执行文件（.exe）
//数据文件：文件的内容不一定是程序，而是程序运行时读写的数据

//1.文件的打开和关闭
//fopen函数：FILE * fopen ( const char * filename, const char * mode );
//常见打开方式有：r：只读，当文件不存在时，会报错
//                w：只写，当文件不存在时，会新建一个文件
//                a：追加，当文件不存在时，会新建一个文件

//fclose函数：关闭文件   int fclose ( FILE * stream );

int main()
{
	//打开文件
	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//2.文件的顺序写入
//fgetc:字符输入函数
//fputc:字符输出函数
//fgets:文本行输入函数
//fputs:文本行输出函数
//fscnaf:格式化输入函数
//fprintf:格式化输出函数
//fread:二进制输入函数
//fwrite:二进制输出函数

int main()
{
	//打开文件
	FILE* pf = fopen("test.dat", "w");//读取时是r，输入时是w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//文件写入
	//fputc('x', pf);
	//fputc('u', pf);
	//fputc('e', pf);
	//fputs("abc\n", pf);
	//fputs("def\n", pf);

	//文件读取
	//int ret = fgetc(pf);
	//printf("%c\n", ret);
	//char arr[10] = {0};
	//fgets(arr, 4, pf);   //实际读取3个字符，因为最后要加上一个\0

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//格式化输入输出函数

struct S
{
	char arr[20];
	int a;
};

int main()
{
	struct S s = { 0};
	FILE* pf = fopen("test.dat", "r");//读取时是r，输入时是w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//输入数据
	//fprintf(pf, "%s %d", s.arr, s.a);

	//读取数据
	fscanf(pf, "%s %d", s.arr, &s.a);
	printf("%s %d", s.arr, s.a);


	fclose(pf);
	pf = NULL;
	return 0;
}

//二进制输入输出数据

struct S
{
	char arr[20];
	int a;
};

int main()
{
	struct S s = { "abc", 10 };
	FILE* pf = fopen("test.dat", "w");//读取时是r，写入时是w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//写入数据
	fwrite(&s, sizeof(struct S), 1, pf);

	//读取数据
	fread(&s, sizeof(struct S), 1, pf);

	fclose(pf);
	pf = NULL;
	return 0;
}