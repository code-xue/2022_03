#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//******************�Լ�ʵ���ַ�������*************************************
//һ��strlen�����������ַ�������
//1.��������

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

//2.ָ��-ָ��

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

//3.�ݹ�

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
//����strcpy����:����һ���ַ�������һ���ַ���

char* my_strcpy(char* dest, const char* sce)
{
	assert(dest);
	assert(sce);
  char* ret = dest;
	int len = strlen(sce);
	int i = 0;
	for (i = 0; i <= len; i++) //strcpyҲ�Ὣ\0���Ƶ�Ŀ���ַ�����

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
//strncpy�����������ַ��������ַ�������

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

//vs�������⺯������
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
	my_strncpy(arr, p, 5);//����ǰ2���ַ���arr��
	printf("%s\n", arr); 
	return 0;
}

//***************************************************************************
//����strcat������׷��һ���ַ�������һ���ַ����ĺ���

char* my_strcat(char* dest, const char* sce)
{
  assert(dest && sce);
	char* ret = dest;
	while (*dest) //�ҵ�Ŀ���ַ�����\0��λ��
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
//strncat�����������ַ��������ַ���׷��

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

//vs�������⺯������
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
//�ġ�strcmp�������Ƚ��������ַ�����С��ǰ>�󣬷���>0,ǰ<�󣬷���<0,ǰ=�󣬷���0

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
//strncmp�����������ַ��������ַ���֮��ıȽ�

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

