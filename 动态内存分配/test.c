#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//********************************************************************
//malloc����������һ���ֽڵ��ڴ�ռ䣬������г�ʼ��
//void* malloc (size_t size);

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	//����40���ֽڵĿռ�
	free(p);
	p = NULL;
	return 0;
}

//***************************************************************************
//calloc����������һ���ֽڵ��ڴ�ռ䣬��ʼ��Ϊ0
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
//realloc�������޸�֮ǰ���ٳ����ڴ�ռ��С
//void* realloc (void* ptr, size_t size);

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		perror("main");
		return;
	}
	//����40���ֽڵĿռ�
	int* ptr = (int*)realloc(p, 100);
	//ע��Ҫ����һ����ʱָ�����realloc�ķ��ؽ�����������p����Ϊ��ָ������
	if (ptr != NULL)
	{
		p = ptr;
	}
	free(p);
	p = NULL;
	return 0;
}

//ʹ�ö�̬�ڴ����ʱ�����Ĵ���
//1.��NULL�Ľ����ò���
//2.�Զ�̬���ٿռ��Խ�����
//3.ʹ��free�ͷŷǶ�̬���ٿռ�
//4.ʹ��free�ͷŶ�̬���ٿռ��һ����
//5.��ͬһ�鶯̬���ٵĿռ����ͷ�
//6.��̬���ٵĿռ������ͷţ�����ڴ�й¶