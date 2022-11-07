//顺序查找 
#include<stdio.h>
#define NUM 8

int source[]={69,65,90,37,92,6,28,54};

int SeqSearch(int s[],int n,int key)
{
    int i;
    for(i=0;i<n&&s[i]!=key;i++);      //将i<n去掉，在优化可以改进算法
    if(i<n)
        return i;
    else
        return -1;
}

int main()
{
    int key,pos;

    printf("原数据为：");
    for(int i=0;i<NUM;i++)
        printf("%d ",source[i]);
        printf("\n");

    printf("请输入关键字：");
    scanf("%d",&key);
    pos=SeqSearch(source,NUM,key);

    if(pos>=0)
        printf("查找成功！在第%d位置！\n",pos+1);
    else
        printf("查找失败！");
    return 0;

}

