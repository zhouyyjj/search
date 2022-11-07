#include <stdio.h>
int main ( )
{
    //冒泡排序
    int a[]={3,2,6,4,8,9,1,0,3,5,7,1};
    int len=sizeof(a)/sizeof(int);//求出数组中元素的个数
//    printf("%d\n",len);
    int i=0,j;
    for (; i<len-1; i++) { //n个元素进行冒泡排序需要进行n-1次循环
        for (j=0; j<len-1-i; j++) { //每次循环完一次，最大的数就在最后，所以每进行一次循环后面的那几个数就不需要参与循环，所以i<len-i-1
            if (a[j]>a[j+1]) {//实现元素的交换
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