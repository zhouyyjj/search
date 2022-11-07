#include <stdio.h>
#include <stdlib.h>
//����������
 
typedef struct BSTNode
{
 int data;
 BSTNode *lchild;  //����
 BSTNode *rchild;  //�Һ���
}BSTNode, *BSTree;
 
bool Search(BSTree bst, int key, BSTree f, BSTree *p);
 
void InOderTraverse(BSTree bst)   //����ݹ����������
{
 if (NULL != bst)
 {
  InOderTraverse(bst->lchild);
  printf("%d ", bst->data);
  InOderTraverse(bst->rchild);
 }
}
 
static BSTNode* BuyNode(int data)   //����һ���ڵ㲢���г�ʼ��
{
 BSTNode *pTmp = (BSTNode*)malloc(sizeof(BSTNode));
 if (NULL == pTmp)
 {
  exit(0);
 }
 pTmp->data = data;
 pTmp->lchild = NULL;
 pTmp->rchild = NULL;
 return pTmp;
}
 
bool Insert(BSTree *bst, int key)
{
 if (NULL == *bst)  //����
 {
  *bst = BuyNode(key);   //������ڵ�
  return true;
 }
 BSTNode *p;
 //���ڶ����������в���Ҫ�����ֵ�Ƿ��Ѿ�����
 if (!Search(*bst, key, NULL, &p))  //�������ʧ�ܣ�����룻��ʱpָ����������һ���ڵ�
 {
  BSTNode *pNew = BuyNode(key);
  if (key < p->data)  //��s��Ϊp������
  {
   p->lchild = pNew;
  }
  else if (key > p->data)  //��s��Ϊp���Һ���
  {
   p->rchild = pNew;
  }
  return true;  //����ɹ�
 }
 else
 {
  printf("\nThe node(%d) already exists.\n", key);
 }
 return false;
}
 
/*
ɾ�������������
(1)��ɾ���Ľڵ��޺��ӣ�˵���ýڵ���Ҷ�ӽڵ㣬ֱ��ɾ
(2)��ɾ���Ľڵ�ֻ�����ӻ����Һ��ӣ�ֱ��ɾ�����������ӻ����Һ��ӷ��ڱ�ɾ�ڵ��λ��
(3)��ɾ���Ľڵ�����Һ��������Һ���
*/
 
BSTNode* FindParent(BSTree bst, BSTNode *child)
{
 if (NULL == bst)
 {
  return NULL;
 }
 
 if (bst->lchild == child || bst->rchild == child)
 {
  return bst;
 }
 else if(NULL != bst->lchild)
 {
  FindParent(bst->lchild, child);
 }
 else if (NULL != bst->rchild)
 {
  FindParent(bst->rchild, child);
 }
}
 
void Delete(BSTree *bst, int key)
{
 if (NULL == *bst)
 {
  exit(1);  //����ֱ�ӱ���
 }
 BSTNode *p;
 BSTNode *f = NULL;
 BSTNode *q, *s;
 if (Search(*bst, key, NULL, &p)) //ȷʵ����ֵΪkey�Ľڵ�,��pָ��ýڵ�
 {
 
  if (NULL == p->lchild && NULL != p->rchild)  //������,���Һ���
  {
   q = p->rchild;
   p->data = q->data;    //��Ϊ�����ڵ�֮�䱾�ʵĲ�ͬ����������Ĳ�ͬ����������ĸ���ַû�й�ϵ
   p->rchild = q->rchild;
   p->lchild = q->lchild;
   free(q);
  }
  else if (NULL == p->rchild && NULL != p->lchild)  //���Һ���,������
  {
   q = p->lchild;
   p->data = q->data;
   p->rchild = q->rchild;
   p->lchild = q->lchild;
   free(q);
  }
  else if (NULL != p->rchild && NULL != p->lchild) //�������ӣ������Һ���
  {
   q = p;
   s = p->lchild;   //�����ӵ����Һ���
   while (s->rchild)
   {
    q = s;
    s = s->rchild;
   }
   p->data = s->data;
 
   if (q != p)
   {
    q->rchild = p->lchild;
   }
   else
   {
    q->lchild = s->lchild;
   }
   free(s);
  }
  else
  {
   if (*bst == p)   //ֻ��һ�����ڵ�
   {
    free(*bst);
    *bst = NULL;
    return;
   }
 
   BSTNode* parent = FindParent(*bst, p);
   if (parent->lchild == p)
   {
    parent->lchild = NULL;
   }
   else
   {
    parent->rchild = NULL;
   }
   free(p);
  }
 }
}
 
bool Search(BSTree bst, int key, BSTree f, BSTree *p)  //���ҳɹ�ʱ��pָ��ֵΪkey�Ľڵ㡣�������ʧ�ܣ���pָ����������һ���ڵ�
{
 if (!bst)
 {
  *p = f;
  return false;
 }
 if (bst->data == key)  //���ҳɹ���ֱ�ӷ���
 {
  *p = bst;
  return true;
 }
 else if (bst->data < key)
 {
  return Search(bst->rchild, key, bst, p);
 }
 return Search(bst->lchild, key, bst, p);
}
 
int main(void)
{
 BSTNode *root = NULL;
 Insert(&root, 45);
 Insert(&root, 24);
 Insert(&root, 53);
 Insert(&root, 12);
 Insert(&root, 90);
 InOderTraverse(root);
 printf("\n%d ", Insert(&root, 45));   //���0��ʾ����ʧ�ܣ����1��ʾ����ɹ�
 printf("%d\n", Insert(&root, 4));
 InOderTraverse(root);
 printf("\n");
 Delete(&root, 4);      //ɾ���ڵ�45
 Delete(&root, 45);      //ɾ���ڵ�45
 Delete(&root, 24);      //ɾ���ڵ�45
 Delete(&root, 53);      //ɾ���ڵ�45
 Delete(&root, 12);      //ɾ���ڵ�45
 Delete(&root, 90);      //ɾ���ڵ�45
 InOderTraverse(root);
 return 0;
}
