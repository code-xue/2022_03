#define _CRT_SECURE_NO_WARNINGS 1

//1.KiKiѧ����printf����Ļ�����Ϣ���������һ��С�ɻ����������д����������С�ɻ���

#include <stdio.h>
int main()
{
    printf("     **     \n");
    printf("     **     \n");
    printf("************\n");
    printf("************\n");
    printf("    *  *    \n");
    printf("    *  *    \n");
    return 0;
}


//2.ţţ�ոճ������໴�����һ��ʼ��ֻ��ѧ˵�򵥵����֣������˵һ�������������̾���ѧ�ᡣ

//����һ��������������������

#include<stdio.h>
int main()
{
    int x = 0;
    scanf("%d", &x);
    printf("%d\n", x);
    return 0;
}

//3.��˵����֮��ţţ��ʼ���Ը�������С����

//����һ������������������������

#include<stdio.h>
int main()
{
    float x = 0;
    scanf("%f", &x);
    printf("%.3f", x);
    return 0;
}

//4.��˵������֮��ţţ��ʼ�����ַ�

//����һ���ַ����������ַ���

#include<stdio.h>
int main()
{
    char c = 0;
    scanf("%c", &c);
    printf("%c\n", c);
    return 0;
}

//5.ţţ�Ӽ�����������������������������Ļ����ʾ�ڶ���������

#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", b);
    return 0;
}