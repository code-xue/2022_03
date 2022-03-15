#define _CRT_SECURE_NO_WARNINGS 1

//1.KiKi学会了printf在屏幕输出信息，他想输出一架小飞机。请帮他编写程序输出这架小飞机。

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


//2.牛牛刚刚出生，嗷嗷待哺，一开始他只能学说简单的数字，你跟他说一个整数，他立刻就能学会。

//输入一个整数，输出这个整数。

#include<stdio.h>
int main()
{
    int x = 0;
    scanf("%d", &x);
    printf("%d\n", x);
    return 0;
}

//3.会说整数之后，牛牛开始尝试浮点数（小数）

//输入一个浮点数，输出这个浮点数。

#include<stdio.h>
int main()
{
    float x = 0;
    scanf("%f", &x);
    printf("%.3f", x);
    return 0;
}

//4.会说浮点数之后，牛牛开始尝试字符

//输入一个字符，输出这个字符。

#include<stdio.h>
int main()
{
    char c = 0;
    scanf("%c", &c);
    printf("%c\n", c);
    return 0;
}

//5.牛牛从键盘上输入三个整数，并尝试在屏幕上显示第二个整数。

#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", b);
    return 0;
}