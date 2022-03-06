#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DEFAULT_SZ 3 //Ĭ�Ͽɴ洢��ϵ������
#define INC_SZ 2     //ÿ���������ӵ���ϵ������

enum menu
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

//ÿ����ϵ�˵���Ϣ
typedef struct PeoInfo
{
	char name[20]; //����
	char tel[20];  //�绰
	int age;       //����
	char sex[10];      //�Ա�
	char addr[20];     //��ַ
}PeoInfo;

//ͨѶ¼����
typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity; 
}Contact;


void InitContact(Contact* pc);
void AddContact(Contact* pc);
void PintfContact(Contact* pc);
void SearchContact(Contact* pc);
void DeleteContact(Contact* pc);
void ModifyContact(Contact* pc);
void SortContactByName(Contact* pc);
void DestoryContact(Contact* pc);