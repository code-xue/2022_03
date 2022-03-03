#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


//*-******************************************************
//strstr函数：判断前一个字符串中是否包含后一个字符串

//暴力比较法
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cp = str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cp;
		}
		cp++;
	}
	return NULL;

}


int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "cde";
	char* ret = my_strstr(arr1, arr2);
	if (ret != NULL)
	{
		printf("%s\n", ret);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}


//*****************************************************************
//strtok函数：将字符串按照特征字符分割
//char * strtok ( char * str, const char * delimiters );
//参数中前一个指针不为空，从第一个字符开始找，找到特征字符后将其改为\0，并在这个位置作上标记，返回开始处的地址
//参数中前一个指针为NULL，从标记位置开始往后找，并在找到特征字符时返回开始处的地址
//找不到特征字符时，返回NULL

int main()
{
	char arr[] = "1282154067@qq.com";
	char* p = "@.";//将@和.作为特征字符进行分割
	//strtok函数会改变字符串内容，所以一般先将字符串复制一份
	char tmp[20] = { 0 };
	strcpy(tmp, arr);
	char* ret = NULL;
	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	
    return 0;
}

//*****************************************************
//strerror函数：读取库函数错误码的信息

#include<errno.h>
int errno;//保存错误码

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

//也可使用perror函数直接输出错误信息
//不需要再创建errno变量
//还可以自定义添加想要输出的内容

int main()
{
	FILE* pf = fopen("test.txt","r");
	if (pf == NULL)
	{
		perror("");
		return 1;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

//*******************************************************************************
//字符分类函数：
//iscntrl  任何控制字符
//isspace  空白字符
//isdigit  十进制数字0-9
//isxdigit 十六进制数字
//islower  小写字符
//isupper  大写字符
//isalpha  字母A-Z和a-z
//isalnum  字母或数字
//ispunct  标点符号
//isgraph  任何图形字符
//isprint  任何可打印字符

//**********************************************************************************
//字符转换函数
//tolower  大写转小写
//toupper  小写转大写