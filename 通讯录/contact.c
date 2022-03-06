#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
}

//销毁通讯录
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//添加联系人
void AddContact(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//通讯录增容
		PeoInfo* ptr = (PeoInfo*)realloc((void*)pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
	}
	scanf("%s", pc->data[pc->sz].name);
	scanf("%s", pc->data[pc->sz].tel);
	scanf("%d", &pc->data[pc->sz].age);
	scanf("%s", pc->data[pc->sz].sex);
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("添加成功\n");
}

//显示通讯录
void PintfContact(Contact* pc)
{ 
	printf("%-20s %-20s %-20s %-20s %-20s\n", "名字", "电话", "年龄", "性别", "地址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s %-20s %-20d %-20s %-20s\n",
			pc->data[i].name,
			pc->data[i].tel,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr);
			
	}
}

//通过名字查找联系人
int find_name(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//搜索通讯录
void SearchContact(Contact* pc)
{
	char name[20] = { 0 };
	printf("输入联系人名字：");
	scanf("%s", name);
	int i = find_name(pc, name);
	if (i == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%-20s %-20s %-20s %-20s %-20s\n", "名字", "电话", "年龄", "性别", "地址");
		printf("%-20s %-20s %-20d %-20s %-20s\n",
			pc->data[i].name,
			pc->data[i].tel,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr);
	}
}

//删除联系人
void DeleteContact(Contact* pc)
{
	char name[20] = { 0 };
	printf("输入联系人名字：");
	scanf("%s", name);
	int i = find_name(pc, name);
	if (i == -1)
	{
		printf("找不到\n");
	}
	else
	{
		for (i; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}

//修改联系人信息
void ModifyContact(Contact* pc)
{
	char name[20] = { 0 };
	printf("输入联系人名字：");
	scanf("%s", name);
	int i = find_name(pc, name);
	if (i == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("请修改：");
		scanf("%s", pc->data[i].name);
		scanf("%s", pc->data[i].tel);
		scanf("%d", &pc->data[i].age);
		scanf("%s", pc->data[i].sex);
		scanf("%s", pc->data[i].addr);
		printf("修改成功\n");
	}
}


int cmp_strcut(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);
}

//通讯录通过名字排序
void SortContactByName(Contact* pc)
{
	qsort((void*)pc->data, pc->sz, sizeof(pc->data[0]), cmp_strcut);
	printf("排序完成\n");
}