#include <stdio.h>								//标准输入/输出函数库
#include <stdlib.h>								//标准函数库

#define MAX_NAME 11
#define MAX_SEX 3
#define MAX_BIRTHDAY 9
#define MAX_TEL 21
#define MAX_MOBILE 21
#define MAX_FAX 21
#define MAX_ADDRESS 101
#define MAX_POSTAL_CODE 7

typedef struct _person 
{
	char name[MAX_NAME];						//姓名
	char sex[MAX_SEX];							//性别
	char birthday[MAX_BIRTHDAY];				//出生日期
	char tel[MAX_TEL];							//电话
	char mobile[MAX_MOBILE];					//手机
	char fax[MAX_FAX];							//传真
	char address[MAX_ADDRESS];					//地址
	char postal_code[MAX_POSTAL_CODE];			//邮编
}person;

typedef struct _addr_book
{
	person per;									//联系人基本信息
	struct _addr_book* next;
}addr_book;

addr_book* first = NULL;						//*addr_book结构体，链表的头节点，置空

void add();										//添加联系人函数
void show();									//显示联系人函数
void search();									//查找联系人函数
void delete();									//删除联系人函数
void update();									//更新联系人函数
void save();									//保存到文件
void quit();									//退出

int print_menu();								//打印主菜单界面
addr_book* get_last(addr_book* from);			//取得链表最后一个值
void print_person(person* p);					//显示一个联系人信息
void input_person(person* p);					//提示输入一个联系人的具体信息

char menu[]=
"+=========================================================================+\n"
"| 通讯簿管理系统							\n"
"+=========================================================================+\n"
"| 1 添加联系人								\n"
"| 2 显示所有联系人							\n"
"| 3 查找联系人								\n"
"| 4 删除联系人								\n"
"| 5 更新联系人								\n"
"| 6 保存									\n"
"| 7 退出系统								\n"
"+==========================================================================+\n";

int main()
{
	print_menu();
	int flg = 1;
	while (flg)
	{
		switch (print_menu())
		{
		case 1:
			add();
			break;
		case 2:
			show();
			break;
		case 3:
			search();
			break;
		case 4:
			delete();
			break;
		case 5:
			update();
			break;
		case 6:
			save();
			break;
		case 7:
			quit();
			break;
		}
	}
}

void add()
{
	char input = "N";
	addr_book *last = NULL;
	addr_book* new_addr = (addr_book*)malloc(sizeof(addr_book));
	//将new_addr中的前addr_book个长度的初值设置为0
	memset(new_addr, 0, sizeof(addr_book));
	new_addr->next = NULL;
	if (first == NULL)
	{
		first = new_addr;
	}
	else
	{
		last = get_last(first);
		last->next = new_addr;
	}
	input_person(&(new_addr->per));
	printf(">继续输入？(Y 继续, N 返回菜单)");
	getchar();
	input = getchar();
	if (input == 'Y' || input == 'y')
	{
		add();
	}
}

void show()
{
	int i = 0;
	addr_book* p = first;
	while (p != NULL)
	{
		i++;
		printf("*****第%d个联系人****************************************\n", i);
		print_person(&(p->next));
		p = p->next;
	}
	if (i == 0)
	{
		printf("没有联系人！");
	}
	printf("按任意键返回菜单...");
	getchar();
	getchar();
}



int print_menu()
{
	int selected = 0;
	system("cls");
	printf(menu);
	printf(">请选择[1----7]:");
	scanf_s("%d", &selected);
	if (selected < 1 || selected >7)
	{
		printf("错误的选择！(请输入1-----7).请按任意键继续...");
		getchar();
		getchar();
	}
	return selected;
}
