#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct S
{
	int i;
	int arr[];//�������飬�ɸ��������������ռ�ڴ��С
	//�����ֶ��巽����arr[]��arr[0], ����һ��ÿ����������֧��
};

//����������ص㣺
//1.�ṹ�е����������Աǰ�������һ���������͵ĳ�Ա
//2.ʹ��sizeof���صĽṹ��С��������������Ĵ�С
//2.ʹ��malloc��������ռ�ʱ����Ŀռ��С����С�ڽṹ��Ĵ�С

int main()
{
	//Ϊ�������鿪��10�����ʹ�С�Ŀռ�
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