#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//�ļ���Ϊ�����ļ��������ļ�
//�����ļ�����Դ�����ļ���.c����Ŀ���ļ���.obj������ִ���ļ���.exe��
//�����ļ����ļ������ݲ�һ���ǳ��򣬶��ǳ�������ʱ��д������

//1.�ļ��Ĵ򿪺͹ر�
//fopen������FILE * fopen ( const char * filename, const char * mode );
//�����򿪷�ʽ�У�r��ֻ�������ļ�������ʱ���ᱨ��
//                w��ֻд�����ļ�������ʱ�����½�һ���ļ�
//                a��׷�ӣ����ļ�������ʱ�����½�һ���ļ�

//fclose�������ر��ļ�   int fclose ( FILE * stream );

int main()
{
	//���ļ�
	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

//2.�ļ���˳��д��
//fgetc:�ַ����뺯��
//fputc:�ַ��������
//fgets:�ı������뺯��
//fputs:�ı����������
//fscnaf:��ʽ�����뺯��
//fprintf:��ʽ���������
//fread:���������뺯��
//fwrite:�������������

int main()
{
	//���ļ�
	FILE* pf = fopen("test.dat", "w");//��ȡʱ��r������ʱ��w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//�ļ�д��
	//fputc('x', pf);
	//fputc('u', pf);
	//fputc('e', pf);
	//fputs("abc\n", pf);
	//fputs("def\n", pf);

	//�ļ���ȡ
	//int ret = fgetc(pf);
	//printf("%c\n", ret);
	//char arr[10] = {0};
	//fgets(arr, 4, pf);   //ʵ�ʶ�ȡ3���ַ�����Ϊ���Ҫ����һ��\0

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

//��ʽ�������������

struct S
{
	char arr[20];
	int a;
};

int main()
{
	struct S s = { 0};
	FILE* pf = fopen("test.dat", "r");//��ȡʱ��r������ʱ��w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//��������
	//fprintf(pf, "%s %d", s.arr, s.a);

	//��ȡ����
	fscanf(pf, "%s %d", s.arr, &s.a);
	printf("%s %d", s.arr, s.a);


	fclose(pf);
	pf = NULL;
	return 0;
}

//�����������������

struct S
{
	char arr[20];
	int a;
};

int main()
{
	struct S s = { "abc", 10 };
	FILE* pf = fopen("test.dat", "w");//��ȡʱ��r��д��ʱ��w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//д������
	fwrite(&s, sizeof(struct S), 1, pf);

	//��ȡ����
	fread(&s, sizeof(struct S), 1, pf);

	fclose(pf);
	pf = NULL;
	return 0;
}