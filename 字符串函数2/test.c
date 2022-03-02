#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


//*-******************************************************
//strstr�������ж�ǰһ���ַ������Ƿ������һ���ַ���

//�����ȽϷ�
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
		printf("�Ҳ���\n");
	}
	return 0;
}
