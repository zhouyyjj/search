#include <stdio.h>
int main ( )
{
    //ð������
    int a[]={3,2,6,4,8,9,1,0,3,5,7,1};
    int len=sizeof(a)/sizeof(int);//���������Ԫ�صĸ���
//    printf("%d\n",len);
    int i=0,j;
    for (; i<len-1; i++) { //n��Ԫ�ؽ���ð��������Ҫ����n-1��ѭ��
        for (j=0; j<len-1-i; j++) { //ÿ��ѭ����һ�Σ������������������ÿ����һ��ѭ��������Ǽ������Ͳ���Ҫ����ѭ��������i<len-i-1
            if (a[j]>a[j+1]) {//ʵ��Ԫ�صĽ���
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    for (i=0; i<len; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
}