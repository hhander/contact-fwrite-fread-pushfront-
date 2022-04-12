#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

enum option
{
	Exit,
	Add,
	Del,
	Modify,
	Find,
	Sort,
	Save,
	PushFront,
	PopFront,
	Show
};






typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}PeoInfo;

typedef struct ContactData
{
	PeoInfo* data;
	int size;
	int capacity;
}Contact;



void InitContact(Contact* ps);
void AddContact(Contact* ps);
void CheckContact(Contact* ps);
void DestroyContact(Contact* ps);
void ShowContact(Contact* ps);
void DelContact(Contact* ps);
void ContactModify(Contact* ps);
void FindContact(Contact* ps);
void SaveContact(Contact* ps);
void LoadContact(Contact* ps);
void SortContact(Contact* ps);
void PushFrontContact(Contact* ps);
void PopFrontContact(Contact* ps);