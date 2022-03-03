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


//*****************************************************************
//strtok���������ַ������������ַ��ָ�
//char * strtok ( char * str, const char * delimiters );
//������ǰһ��ָ�벻Ϊ�գ��ӵ�һ���ַ���ʼ�ң��ҵ������ַ������Ϊ\0���������λ�����ϱ�ǣ����ؿ�ʼ���ĵ�ַ
//������ǰһ��ָ��ΪNULL���ӱ��λ�ÿ�ʼ�����ң������ҵ������ַ�ʱ���ؿ�ʼ���ĵ�ַ
//�Ҳ��������ַ�ʱ������NULL

int main()
{
	char arr[] = "1282154067@qq.com";
	char* p = "@.";//��@��.��Ϊ�����ַ����зָ�
	//strtok������ı��ַ������ݣ�����һ���Ƚ��ַ�������һ��
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
//strerror��������ȡ�⺯�����������Ϣ

#include<errno.h>
int errno;//���������

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