#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu()
{
	printf("***********************************\n");
	printf("*****  1. Add        2. Del   *****\n");
	printf("*******3. Modify     4. Find *****\n");
	printf("*******5. Sort       6. Save  *****\n");
	printf("*******7. Push front 8. Pop front**\n");
	printf("*******9. Show       0. exit  *****\n");
	printf("***********************************\n");
}



int main()
{
	printf("欢迎来到通讯录\n");
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请输入您的选项\n");
		scanf("%d", &input);
		switch(input)
		{
			case Add:
			{
				AddContact(&con);
				break;
			}
			case Del:
			{
				DelContact(&con);
				break;
			}
			case Modify:
			{
				ContactModify(&con);
				break;
			}
			case Find:
			{
				FindContact(&con);
				break;
			}
			case Sort:
			{
				SortContact(&con);
				break;
			}
			case Save:
			{
				SaveContact(&con);
				DestroyContact(&con);
				break;
			}
			case Exit:
			{
				SaveContact(&con);
				DestroyContact(&con);
				printf("exit suceess\n");
				break;
			}
			case Show:
			{
				ShowContact(&con);
				break;
			}
			case PushFront:
			{
				PushFrontContact(&con);
				break;
			}
			case PopFront:
			{
				PopFrontContact(&con);
				break;
			}
			default :
			{
				printf("option not exist\n");
				break;
			}
		}

	} while (input);

	return 0;
}
