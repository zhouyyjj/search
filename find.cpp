#include<stdio.h>
#include<stdlib.h>
 
//二分法查找
int search(int a[],int length, int x)       //a是搜索数组，x为搜索元素
{
 int i = 0, j = 0;
 int detection = -1;//标志位
 int top = length - 1; // 数组的右边界
 int middle = 0;  //中间值的下标
 int low = 0; //数组的左边界
 
 while (low <= top)
 {
  middle = (low + top) / 2;
  if (a[middle] == x)
  {
   detection = middle;
  }
  if (a[middle] < x)
  {
   low = middle + 1;
  }
  else
  {
   top = middle - 1;
  }
 }
 if (detection == -1)
 {
  //如果x没有在其中，则执行完，top为底，low为顶，x在中间。
  i = top;
  j = low;
 }
 else
 {
  i = detection;
  j = i;
 }
 
 printf("i的值为：%d\nj的值为：%d\n",i,j);
 return 0;
}
 
void main()
{
 int arr[] = { 1,2,3,4,5,6,7,8,55,60,100 };
 int length = sizeof(arr) / sizeof(int);
 search(arr,length,2);
 system("pause");
}