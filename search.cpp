#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
 
//���͵�����
 
#define MAX 1000
 
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
 
//ͨѶ¼��ʼ״̬��������С
#define DEFAULT_SZ 3
 
enum Option
{
 EXIT,//0
 ADD,
 DEL,
 SEARCH,
 MODIFY,
 SORT,
 PRINT
};
enum Con
{
 ERRO,
 NAME,
 SEX,
 AGE,
 TELE,
 ADDR
};
 
typedef struct PeoInfo
{
 char name[NAME_MAX];
 char sex[SEX_MAX];
 int age;
 char tele[TELE_MAX];
 char addr[ADDR_MAX];
} PeoInfo;
typedef struct Contact
{
 PeoInfo* data;//���Դ��1000���˵���Ϣ
 int sz;//��¼ͨѶ���Ѿ��������Ϣ����
 int capacity;//��¼ͨѶ¼��ǰ���������
}Contact;
//����������
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//����ͨѶ¼
void DestroyContact(Contact* pc);
//������ϵ�˵���Ϣ
void AddContact(Contact* pc);
//��ӡͨѶ¼�е���Ϣ
void PrintContact(const Contact* pc);
//ɾ��ָ����ϵ��
void DelContact(Contact* pc);
//����ָ����ϵ��
void SearchContact(const Contact* pc);
//����ͨѶ¼����Ϣ���ļ�
void SaveContact(const Contact* pc);
//ͨѶ¼����
void SortCon(Contact* pc);
void ModifyCon(Contact* pc);
#define _CRT_SECURE_NO_WARNINGS 1
 
//��̬�İ汾
//void InitContact(Contact* pc)
//{
// assert(pc);
// pc->sz = 0;
// pc->capacity = DEFAULT_SZ;
// pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
//
// if (pc->data == NULL)
// {
//  perror("InitContact::malloc");
//  return;
// }
// memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));
//}
void CheckCapacity(Contact* pc)
{
 //���ݵĴ���
 if (pc->sz == pc->capacity)
 {
  PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
  if (tmp != NULL)
  {
   pc->data = tmp;
  }
  else
  {
   perror("CheckCapacity::realloc");
   return;
  }
  pc->capacity += 2;
  printf("���ݳɹ�\n");
 }
}
void LoadContact(Contact* pc)
{
 //���ļ�
 FILE* pf = fopen("contact.dat", "rb");
 if (pf == NULL)
 {
  perror("LoadContact::fopen");
  return;
 }
 //���ļ�
 PeoInfo tmp = { 0 };
 while (fread(&tmp, sizeof(PeoInfo), 1, pf))
 {
  CheckCapacity(pc);
  pc->data[pc->sz] = tmp;
  pc->sz++;
 }
 
 //�ر��ļ�
 fclose(pf);
 pf = NULL;
}
//��ʼ��ͨѶ¼ - �ļ��汾
void InitContact(Contact* pc)
{
 assert(pc);
 pc->sz = 0;
 pc->capacity = DEFAULT_SZ;
 pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
 
 if (pc->data == NULL)
 {
  perror("InitContact::malloc");
  return;
 }
 memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));
 
 //�����ļ���Ϣ��ͨѶ¼��
 LoadContact(pc);
}
void DestroyContact(Contact* pc)
{
 free(pc->data);
 pc->data = NULL;
 pc->capacity = 0;
 pc->sz = 0;
 printf("���ٳɹ�\n");
}
void AddContact(Contact* pc)
{
 assert(pc);
 
 //��̬�汾
 //if (pc->sz == MAX)
 //{
 // printf("ͨѶ¼�������޷����\n");
 // return;
 //}
 
 //��̬�İ汾
 CheckCapacity(pc);
 
 //¼����Ϣ
 printf("����������:>");
 scanf("%s", pc->data[pc->sz].name);
 printf("����������:>");
 scanf("%d", &(pc->data[pc->sz].age));
 printf("�������Ա�:>");
 scanf("%s", pc->data[pc->sz].sex);
 printf("������绰:>");
 scanf("%s", pc->data[pc->sz].tele);
 printf("�������ַ:>");
 scanf("%s", pc->data[pc->sz].addr);
 
 pc->sz++;
 printf("��ӳɹ�\n");
}
void PrintContact(const Contact* pc)
{
 assert(pc);
 
 int i = 0;
 printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
 
 for (i = 0; i < pc->sz; i++)
 {
  printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
 }
}
 
//�ҵ��˷����±�
//�Ҳ�������-1
int FindByName(const Contact* pc, char name[])
{
 assert(pc);
 int i = 0;
 for (i = 0; i < pc->sz; i++)
 {
  if (0 == strcmp(pc->data[i].name, name))
  {
   return i;
  }
 }
 
 return -1;
}
 
void DelContact(Contact* pc)
{
 assert(pc);
 
 if (pc->sz == 0)
 {
  printf("ͨѶ¼�ѿգ��޷�ɾ��\n");
  return;
 }
 //ɾ��
 //1. �ҵ�
 char name[NAME_MAX] = { 0 };
 printf("������Ҫɾ���˵�����:>");
 scanf("%s", name);
 int pos = FindByName(pc, name);
 if (pos == -1)
 {
  printf("Ҫɾ�����˲�����\n");
  return;
 }
 //2. ɾ��
 int j = 0;
 for (j = pos; j < pc->sz - 1; j++)
 {
  pc->data[j] = pc->data[j + 1];
 }
 
 pc->sz--;
 printf("ɾ���ɹ�\n");
}
 
void SearchContact(const Contact* pc)
{
 char name[NAME_MAX] = { 0 };
 printf("������Ҫ�����˵�����:>");
 scanf("%s", name);
 int pos = FindByName(pc, name);
 if (pos == -1)
 {
  printf("Ҫ���ҵ��˲�����\n");
  return;
 }
 printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
 printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex,
  pc->data[pos].tele, pc->data[pos].addr);
}
 
 
void SaveContact(const Contact* pc)
{
 FILE* pf = fopen("contact.dat", "wb");
 //�������ؽ���һ��contact.dat�ļ��±�
 if (pf == NULL)
 {
  perror("SaveContact::fopen");
  return;
 }
 //д�ļ�
 int i = 0;
 for (i = 0; i < pc->sz; i++)
 {
  fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
 }
 
 //�ر��ļ�
 fclose(pf);
 pf = NULL;
}
void SortCon(Contact* pc)
{
 if (pc->sz == 0)
 {
  printf("ͨѶ¼��û����ϵ��\n");
 }
 else
 {
  for (int i = 0; i < pc->sz - 1; i++)
  {
   for (int j = 0; j < pc->sz - 1 - i; j++)
   {
    if ((strcmp(pc->data[j].name, pc->data[j + 1].name)) > 0)
    {
     PeoInfo temp = pc->data[j];
     pc->data[j] = pc->data[j + 1];
     pc->data[j + 1] = temp;
    }
   }
  }
  printf("����ɹ���\n");
 }
}
 
void ModifyCon(Contact* pc)
{
 assert(pc);
 char name[NAME_MAX];
 printf("��������Ҫ�޸���Ϣ�û�������:>\n");
 scanf("%s", name);
 int pos = FindByName(pc, name);//posΪҪѰ�ҵ��˵��±�
 if (pos == -1)
 {
  printf("���޴���\n");
 }
 else
 {
  int num = 0;
  do {
   printf("�����������޸Ĵ��û�����Ϣ\n");
   printf(" 0.�˳� 1.���� 2.�Ա� 3.���� 4.�绰 5.��ַ:>\n");
   scanf("%d", &num);
   switch (num)
   {
   case NAME:
    printf("�����������޸ĵ�����:>\n");
    scanf("%s", pc->data[pos].name);
    break;
   case SEX:
    printf("�����������޸ĵ��Ա�:>\n");
    scanf("%s", pc->data[pos].sex);
    break;
   case AGE:
    printf("�����������޸ĵ�����:>\n");
    scanf("%d", &(pc->data[pos].age));
    break;
   case TELE:
    printf("�����������޸ĵĵ绰:>\n");
    scanf("%s", pc->data[pos].tele);
    break;
   case ADDR:
    printf("�����������޸ĵĵ�ַ:>\n");
    scanf("%s", pc->data[pos].addr);
    break;
   case 0:
    printf("���޸��˻ؽ���\n");
    break;
   default:printf("��Ч��������\n");
   }
  } while (num);
 }
}
 
void menu()
{
 printf("*****************************************\n");
 printf("**** 1.������ϵ��    2.ɾ����ϵ��    ****\n");
 printf("**** 3.������ϵ��    4.�޸���ϵ��    ****\n");
 printf("**** 5.ͨѶ¼����    6.��ӡͨѶ¼    ****\n");
 printf("****            0.�˳�               ****\n");
 printf("******************************************\n");
}
 
void test()
{
 int input = 0;
 Contact con;
 InitContact(&con);
 
 do
 {
  menu();
  printf("���������ѡ��:>");
  scanf("%d", &input);
  switch (input)
  {
  case ADD:
   AddContact(&con);
   break;
  case DEL:
   DelContact(&con);
   break;
  case SEARCH:
   SearchContact(&con);
   break;
  case MODIFY:
   ModifyCon(&con);
   break;
  case SORT:
   SortCon(&con);
   break;
  case PRINT:
   PrintContact(&con);
   break;
  case EXIT:
   SaveContact(&con);
   DestroyContact(&con);
   printf("��лʹ��\n");
   break;
  default:
   printf("�Ƿ�����\n");
   break;
  }
 } while (input);
}
 
int main()
{
 test();
 return 0;
}
