#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//******************自己实现字符串函数*************************************
//一、strlen函数：计算字符串长度
//1.计数器法

int my_strlen(char* str)
{
  assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char arr[] = { "abc" };
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

//2.指针-指针

int my_strlen(char* str)
{
  assert(str);
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

int main()
{
	char arr[] = { "abc" };
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

//3.递归

int my_strlen(char* str)
{
  assert(str);
	if (*str != '\0')
	{
		str++;
		return 1 + my_strlen(str);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = { "abc" };
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}


//*****************************************************
//二、strcpy函数:复制一个字符串到另一个字符串

char* my_strcpy(char* dest, const char* sce)
{
	assert(dest);
	assert(sce);
  char* ret = dest;
	int len = strlen(sce);
	int i = 0;
	for (i = 0; i <= len; i++) //strcpy也会将\0复制到目标字符串中

	{
		*dest = *sce;
		dest++;
		sce++;
	}
  return ret;
}

int main()
{
	char arr[] = { "abcd" };
	char* p = "efg";
	my_strcpy(arr, p);
	printf("%s\n", arr); 
	return 0;
}

//******************************************************************
//strncpy函数：限制字符个数的字符串复制

char* my_strncpy(char* dest, const char* sce, int k)
{
	char* ret = dest;
	int i = 0;
	for (i = 0; i < k; i++)
	{
		if(*sce != '\0')
		{
			*dest++ = *sce++;
		}
		else
		{
			break;
		}
	}
	for (i; i < k; i++)
	{
		*dest++ = '\0';
	}
	return ret;
}

//vs编译器库函数代码
//char* my_strncpy(char* dest, const char* sce, int count)
//{
//	char* tmp = dest;
//	while (count && (*dest++ = *sce++) != '\0')
//	{
//		count--;
//	}
//	if (count)
//	{
//		while (--count)
//		{
//			*dest++ = '\0';
//		}
//	}
//	return tmp;
//}

int main()
{
	char arr[20] = { "abcd" };
	char* p = "efg";
	my_strncpy(arr, p, 5);//复制前2个字符到arr中
	printf("%s\n", arr); 
	return 0;
}

//***************************************************************************
//三、strcat函数：追加一个字符串到另一个字符串的后面

char* my_strcat(char* dest, const char* sce)
{
  assert(dest && sce);
	char* ret = dest;
	while (*dest) //找到目标字符串中\0的位置
	{
		dest++;
	}
	while (*dest++ = *sce++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "world";
	printf("%s\n", my_strcat(arr1, arr2));
	return 0;
}

//**********************************************************
//strncat函数：限制字符个数的字符串追加

char* my_strncat(char* dest, const char* sce, int count)
{
	assert(dest && sce);
	char* start = dest;
	while (*dest++)
	{
		;
	}
	dest--;
	while (count && (*dest++ = *sce++) != '\0')
	{
		count--;
	}
	if (count == 0)
	{
		*dest = '\0';
	}
	return start;
}

//vs编译器库函数代码
//char* my_strncat(char* dest, const char* sce, int count)
//{
//	char* start = dest;
//	while (*dest++)
//	{
//		;
//	}
//	dest--;
//	while (count--)
//	{
//		if ((*dest++ = *sce++) == '\0')
//		{
//			return start;
//		}
//	}
//	*dest = '\0';
//	return start;
//}

int main()
{
	char arr[20] = "hello ";
	char* p = "world";
	printf("%s\n", my_strncat(arr, p, 2));
	return 0;
}



//****************************************************************************************
//四、strcmp函数：比较连两个字符串大小，前>后，返回>0,前<后，返回<0,前=后，返回0

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main()
{
	char* p1 = "aab";
	char* p2 = "aacd";
	int ret = my_strcmp(p1, p2);
	if (ret > 0)
	{
		printf("p1 > p2\n");
	}
	else if (ret < 0)
	{
		printf("p1 < p2\n");
	}
	else
	{
		printf("p1 == p2\n");
	}
	return 0;
}

//***************************************************************************************
//strncmp函数：限制字符个数的字符串之间的比较

int my_strncmp(const char* str1, const char* str2, int count)
{
	assert(str1 && str2);
	while (count--)
	{
		if (*str1++ != *str2++)
		{
			return str1 - str2;
		}
	}
	return 0;
}

int main()
{
	char* p1 = "abc";
	char* p2 = "abc";
	int ret = my_strncmp(p1, p2, 6);
	if (ret > 0)
	{
		printf("p1 > p2");
	}
	else if (ret < 0)
	{
		printf("p1 < p2");
	}
	else
	{
		printf("p1 == p2");
	}
	return 0;
}

