#include <stdio.h>								//��׼����/���������
#include <stdlib.h>								//��׼������

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
	char name[MAX_NAME];						//����
	char sex[MAX_SEX];							//�Ա�
	char birthday[MAX_BIRTHDAY];				//��������
	char tel[MAX_TEL];							//�绰
	char mobile[MAX_MOBILE];					//�ֻ�
	char fax[MAX_FAX];							//����
	char address[MAX_ADDRESS];					//��ַ
	char postal_code[MAX_POSTAL_CODE];			//�ʱ�
}person;

typedef struct _addr_book
{
	person per;									//��ϵ�˻�����Ϣ
	struct _addr_book* next;
}addr_book;

addr_book* first = NULL;						//*addr_book�ṹ�壬�����ͷ�ڵ㣬�ÿ�

void add();										//�����ϵ�˺���
void show();									//��ʾ��ϵ�˺���
void search();									//������ϵ�˺���
void delete();									//ɾ����ϵ�˺���
void update();									//������ϵ�˺���
void save();									//���浽�ļ�
void quit();									//�˳�

int print_menu();								//��ӡ���˵�����
addr_book* get_last(addr_book* from);			//ȡ���������һ��ֵ
void print_person(person* p);					//��ʾһ����ϵ����Ϣ
void input_person(person* p);					//��ʾ����һ����ϵ�˵ľ�����Ϣ

char menu[]=
"+=========================================================================+\n"
"| ͨѶ������ϵͳ							\n"
"+=========================================================================+\n"
"| 1 �����ϵ��								\n"
"| 2 ��ʾ������ϵ��							\n"
"| 3 ������ϵ��								\n"
"| 4 ɾ����ϵ��								\n"
"| 5 ������ϵ��								\n"
"| 6 ����									\n"
"| 7 �˳�ϵͳ								\n"
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
	//��new_addr�е�ǰaddr_book�����ȵĳ�ֵ����Ϊ0
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
	printf(">�������룿(Y ����, N ���ز˵�)");
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
		printf("*****��%d����ϵ��****************************************\n", i);
		print_person(&(p->next));
		p = p->next;
	}
	if (i == 0)
	{
		printf("û����ϵ�ˣ�");
	}
	printf("����������ز˵�...");
	getchar();
	getchar();
}



int print_menu()
{
	int selected = 0;
	system("cls");
	printf(menu);
	printf(">��ѡ��[1----7]:");
	scanf_s("%d", &selected);
	if (selected < 1 || selected >7)
	{
		printf("�����ѡ��(������1-----7).�밴���������...");
		getchar();
		getchar();
	}
	return selected;
}
