#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu()
{
	printf("******   1.���   2.ɾ��       *****\n");
	printf("******   3.����   4.�޸�       *****\n");
	printf("******   5.����   6.��ʾ       *****\n");
	printf("******       0.�˳�            *****\n");
	printf("************************************\n");
}

int main()
{
	int input = 0;
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}