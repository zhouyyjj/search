//˳����� 
#include<stdio.h>
#define NUM 8

int source[]={69,65,90,37,92,6,28,54};

int SeqSearch(int s[],int n,int key)
{
    int i;
    for(i=0;i<n&&s[i]!=key;i++);      //��i<nȥ�������Ż����ԸĽ��㷨
    if(i<n)
        return i;
    else
        return -1;
}

int main()
{
    int key,pos;

    printf("ԭ����Ϊ��");
    for(int i=0;i<NUM;i++)
        printf("%d ",source[i]);
        printf("\n");

    printf("������ؼ��֣�");
    scanf("%d",&key);
    pos=SeqSearch(source,NUM,key);

    if(pos>=0)
        printf("���ҳɹ����ڵ�%dλ�ã�\n",pos+1);
    else
        printf("����ʧ�ܣ�");
    return 0;

}

