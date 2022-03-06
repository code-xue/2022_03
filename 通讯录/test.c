#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu()
{
	printf("******   1.添加   2.删除       *****\n");
	printf("******   3.查找   4.修改       *****\n");
	printf("******   5.排序   6.显示       *****\n");
	printf("******       0.退出            *****\n");
	printf("************************************\n");
}

int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContactByName(&con);
			PintfContact(&con);
			break;
		case PRINT:
			PintfContact(&con);
			break;
		case EXIT:
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}