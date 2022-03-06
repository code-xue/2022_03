#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
}

//����ͨѶ¼
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//�����ϵ��
void AddContact(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//ͨѶ¼����
		PeoInfo* ptr = (PeoInfo*)realloc((void*)pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
	}
	scanf("%s", pc->data[pc->sz].name);
	scanf("%s", pc->data[pc->sz].tel);
	scanf("%d", &pc->data[pc->sz].age);
	scanf("%s", pc->data[pc->sz].sex);
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}

//��ʾͨѶ¼
void PintfContact(Contact* pc)
{ 
	printf("%-20s %-20s %-20s %-20s %-20s\n", "����", "�绰", "����", "�Ա�", "��ַ");
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

//ͨ�����ֲ�����ϵ��
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

//����ͨѶ¼
void SearchContact(Contact* pc)
{
	char name[20] = { 0 };
	printf("������ϵ�����֣�");
	scanf("%s", name);
	int i = find_name(pc, name);
	if (i == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("%-20s %-20s %-20s %-20s %-20s\n", "����", "�绰", "����", "�Ա�", "��ַ");
		printf("%-20s %-20s %-20d %-20s %-20s\n",
			pc->data[i].name,
			pc->data[i].tel,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr);
	}
}

//ɾ����ϵ��
void DeleteContact(Contact* pc)
{
	char name[20] = { 0 };
	printf("������ϵ�����֣�");
	scanf("%s", name);
	int i = find_name(pc, name);
	if (i == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		for (i; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
	}
}

//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc)
{
	char name[20] = { 0 };
	printf("������ϵ�����֣�");
	scanf("%s", name);
	int i = find_name(pc, name);
	if (i == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("���޸ģ�");
		scanf("%s", pc->data[i].name);
		scanf("%s", pc->data[i].tel);
		scanf("%d", &pc->data[i].age);
		scanf("%s", pc->data[i].sex);
		scanf("%s", pc->data[i].addr);
		printf("�޸ĳɹ�\n");
	}
}


int cmp_strcut(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);
}

//ͨѶ¼ͨ����������
void SortContactByName(Contact* pc)
{
	qsort((void*)pc->data, pc->sz, sizeof(pc->data[0]), cmp_strcut);
	printf("�������\n");
}