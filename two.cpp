#include<stdio.h>
int main()
{
int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//Ҫ����������������
int left = 0;//���±�
 int right = sizeof(arr) / sizeof(arr[0]) - 1;//���±�
 int key = 7;//����û������7
 int mid = 0;
 while (left <= right)
 {
  mid = (left + right) / 2;//�ҵ��м���±�
  if (arr[mid] > key)
  {
   right = mid - 1;//���ȡ���м���Ǹ�����7����˵��7���������벿��
  }
  else if (arr[mid] < key)
  {
   left = mid + 1;//���ȡ���м���Ǹ�����7��С��˵��7��������Ұ벿��
  }
  else
   break;//����ѭ��,˵����ʱ��arr[mid]==key,�ҵ���
 }
 if (left <= right)
 {
  printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
 }
 else
 {
  printf("�Ҳ���\n");
 }
}
