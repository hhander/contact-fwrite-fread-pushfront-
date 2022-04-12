#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


void InitContact(Contact* ps)
{
	ps->capacity = 0;
	ps->data = NULL;
	ps->size = 0;
	LoadContact(ps);
}

void CheckContact(Contact* ps)
{
	int NewCapacity = 0;
	if (ps->size == ps->capacity)
	{
		NewCapacity = ps->capacity == 0 ? 3 : ps->capacity * 2;
		PeoInfo* tmp = (PeoInfo*)realloc(ps->data, NewCapacity * sizeof(PeoInfo));
		if (tmp == NULL)
		{
			printf("realloc faile ");
			exit(-1);
		}
		printf("alloc success\n");
		ps->data = tmp;
		ps->capacity = NewCapacity;
	}
}

void DestroyContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void AddContact(Contact* ps)
{
	CheckContact(ps);
	printf("please enter name\n");
	scanf("%s", ps->data[ps->size].name);
	printf("please enter age\n");
	scanf("%d", &(ps->data[ps->size].age));
	printf("please enter sex\n");
	scanf("%s", ps->data[ps->size].sex);
	printf("please enter telephone\n");
	scanf("%s", ps->data[ps->size].tele);
	printf("please enter address\n");
	scanf("%s", ps->data[ps->size].addr);
    ps->size++;
	printf("add success\n");
}


void ShowContact(Contact* ps)
{
	if (ps->size == 0)
	{
		printf("contact is empty\n");
	}
	else
	{
		printf("%20s\t%5s\t%10s\t%13s\t%30s\t", "name", "age", "sex", "telephone", "address");
		printf("\n");
		for (int i = 0; i < ps->size; i++)
		{
			printf("%20s\t%5d\t%10s\t%13s\t%30s\t", ps->data[i].name, ps->data[i].age, ps->data[i].sex, ps->data[i].tele, ps->data[i].addr);
			printf("\n");
		}
	}



}

int FindPeople(Contact* ps,char ch[])
{
	if (ps->size == 0)
	{
		printf("contact is empty");
	}
	else
	{
		for (int i = 0; i < ps->size; i++)
		{
			if (strcmp(ch, ps->data[i].name)==0)
			{
				return i;
			}
		}
	}
	return -1;
}



void DelContact(Contact* ps)
{
	char ch[30];
	printf("请输入你要删除人的名字\n");
	scanf("%s", ch);
	int i = FindPeople(ps,ch);
	if (i == -1)
	{
		printf("你查找的人不存在\n");
	}
	else
	{
		for (int j = i; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		printf("删除成功\n");
		ps->size--;
	}
}


void ContactModify(Contact* ps)
{
	if (ps->size == 0)
	{
		printf("the contact is empty\n");
	}
	else
	{
		char ch[30];
		printf("enter the name you want to modify");
		scanf("%s", &ch);
		int ret = FindPeople(ps, ch);
		if (ret == -1)
		{
			printf("the person is not exist");
		}
		else
		{
			printf("please modify\n");
			printf("please enter name\n");
			scanf("%s", ps->data[ret].name);
			printf("please enter age\n");
			scanf("%d", &(ps->data[ret].age));
			printf("please enter sex\n");
			scanf("%s", ps->data[ret].sex);
			printf("please enter telephone\n");
			scanf("%s", ps->data[ret].tele);
			printf("please enter address\n");
			scanf("%s", ps->data[ret].addr);
			printf("modify success\n");
		}
	}
}


void FindContact(Contact* ps)
{
	if (ps->size == 0)
	{
		printf("contact is empty\n");
	}
	char ch[30];
	printf("please enter the name you find\n");
	scanf("%s", ch);
	int ret = FindPeople(ps, ch);
	if (ret == -1)
	{
		printf("the person is not exist\n");
	}
	else
	{
		printf("%20s\t%5s\t%10s\t%13s\t%30s\t", "name", "age", "sex", "telephone", "address");
		printf("\n");
		printf("%20s\t%5d\t%10s\t%13s\t%30s\t", ps->data[ret].name, ps->data[ret].age, ps->data[ret].sex, ps->data[ret].tele, ps->data[ret].addr);
		printf("\n");
	}

}

void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contactData.txt", "wb");
	if (pfWrite == NULL)
	{
		printf("pfWrite fail\n");
		exit(-1);
	}
	else
	{
		for (int i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	    }
		printf("save sucess\n");
	}
	fclose(pfWrite);
	pfWrite = NULL;

}


void LoadContact(Contact* ps)
{	
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contactData.txt", "rb");
	if (pfRead == NULL)
	{
		printf("pfRead fail\n");
		exit(-1);
	}
	else
	{
		while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
		{
			CheckContact(ps);
			ps->data[ps->size] = tmp;
			ps->size++;
		}
	}
	fclose(pfRead);
	pfRead = NULL;
}

int cmp_name(void* a,void* b)
{
	return strcmp((*(PeoInfo*)a).name, (*(PeoInfo*)b).name);
}

int cmp_age(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

void SortContact(Contact* ps)
{
	printf("请选择1. 以name排序\n");
	printf("请选择2. 以age 排序\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 1)
	{
		qsort(ps->data, ps->size, sizeof(PeoInfo), cmp_name);

	}
	else
	{
		qsort(ps->data, ps->size, sizeof(PeoInfo), cmp_age);
	}
	printf("sort success\n");
}


void PushFrontContact(Contact* ps)
{
	CheckContact(ps);
	int end = ps->size - 1;
	assert(ps->size >= 0);
	for (int i = 0; i < ps->size; i++)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	printf("请输入要在头部插入的数据\n");
	printf("please enter name\n");
	scanf("%s", ps->data[0].name);
	printf("please enter age\n");
	scanf("%d", &(ps->data[0].age));
	printf("please enter sex\n");
	scanf("%s", ps->data[0].sex);
	printf("please enter telephone\n");
	scanf("%s", ps->data[0].tele);
	printf("please enter address\n");
	scanf("%s", ps->data[0].addr);
	printf("PushFront success\n");
	ps->size++;
}


void PopFrontContact(Contact* ps)
{
	assert(ps->size >= 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
	printf("PopFront Success\n");
}