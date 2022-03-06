#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DEFAULT_SZ 3 //默认可存储联系人数量
#define INC_SZ 2     //每次增容增加的联系人数量

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

//每个联系人的信息
typedef struct PeoInfo
{
	char name[20]; //名字
	char tel[20];  //电话
	int age;       //年龄
	char sex[10];      //性别
	char addr[20];     //地址
}PeoInfo;

//通讯录数据
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