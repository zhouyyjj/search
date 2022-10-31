#include<stdio.h>
int main()
{
int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//要求数组必须是有序的
int left = 0;//左下标
 int right = sizeof(arr) / sizeof(arr[0]) - 1;//右下标
 int key = 7;//看有没有数字7
 int mid = 0;
 while (left <= right)
 {
  mid = (left + right) / 2;//找到中间的下标
  if (arr[mid] > key)
  {
   right = mid - 1;//如果取的中间的那个数比7还大，说明7在数组的左半部分
  }
  else if (arr[mid] < key)
  {
   left = mid + 1;//如果取的中间的那个数比7还小，说明7在数组的右半部分
  }
  else
   break;//跳出循环,说明这时候arr[mid]==key,找到了
 }
 if (left <= right)
 {
  printf("找到了，下标是：%d\n", mid);
 }
 else
 {
  printf("找不到\n");
 }
}
