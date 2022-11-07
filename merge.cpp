//πÈ≤¢≈≈–Ú 
#include <stdio.h>
void merge_sort(int a[],int left,int right){
 if(left<right){
  int mid = (left + right) / 2;
  merge_sort(a,left, mid);
  merge_sort(a, mid + 1, right);
  merge(a, left, right, mid);
 }
}
void merge(int a[],int left,int right,int mid) {
 int s[100];
 int i = left, j = mid + 1;
 int sor = left;
 while (i <= mid && j <= right) {
  if (a[i] < a[j]) {
   s[sor++] = a[i++];
  }
  else {
   s[sor++] = a[j++];
  }
 }
 while (i <= mid) s[sor++] = a[i++];
 while (j <= right)  s[sor++] = a[j++];
 sor = left;
 while (sor <= right) {
  a[sor] = s[sor];
  sor++;
 }
}
int main()
{
  int a[]={3,9,5,4,64,4,5,9,8,9};
  int i;
  merge_sort(a, 0, 9);
  for(i = 0; i < 10; i++)
 {
   printf("%d ", a[i]);
 }
  return 0; 
} 
