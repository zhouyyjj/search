#include <stdio.h>
#include <stdlib.h>

#define keyType int 
typedef struct
{
	keyType key;   //查找表中每个数据元素的值
}ElemType;

typedef struct 
{
	ElemType *elem;//存放查找表中元素的数组
	int length;    //记录查找表中数据的总数量
}SSTable;

//创建查找表
void Create(SSTable *st,int length)
{
	//(*st) = (SSTable *)malloc(sizeof(SSTable));
	st->length = length;
	st->elem = (ElemType *)malloc((length + 1)*sizeof(ElemType));
	printf("输入表中的数据元素:\n");
	//根据查找表中数据元素的总长度，在存储时，从数组下标为1的空间开始存储数据
	for (int i = 1;i<=length;i++)
	{
		scanf("%d",&(st->elem[i].key));
	}
}

int search_seq(SSTable *st,keyType key)
{
	st->elem[0].key = key;    //将关键字作为一个数据元素放到查找表的第一个位置，起监视哨的作用
	int i = st->length;
	//从查找表的最后一个数据元素依次遍历，一直遍历到数组下标为0
	while(st->elem[i].key!=key)
	{
		i--;
	}
	//如果 i = 0，说明查找失败，反之，返回的是含有关键字key的数据元素在查找表中的位置
	return i;
}

int main()
{
	SSTable st;
	Create(&st,6);
	printf("请输入要查找数据的关键字:\n");
	int key;
	scanf("%d",&key);
	
	int location = search_seq(&st,key);
	if(location == 0)
	{
		printf("查找失败\n");
	}
	else
	{
		printf("数据在查找表中的位置为:%d\n",location);
	}
	return 0;
}