//插入排序 
#include <stdio.h>
int main()
{
    int arr[6]={4,6,1,2,8,7};
    int n = sizeof(arr)/sizeof(int); //求出数组的长度
    int i,j,k;
    for (i=1; i<n; i++) {
        k = arr[i];  //哨兵,从数组中的第二个元素开始进行存储，每一次往后移动一位进行储存，将这个数插入到前面已经排好序的数组中。
        j=i-1;   //已经排好序的数组的最后一个元素的下标。
        while(j>=0 && k<arr[j]){ //每次哨兵和前面排好序的数组中的元素从后往前进行比较，找到哨兵要插入的位置。
            arr[j+1]=arr[j]; //为哨兵腾出位置，以便于将哨兵插入数组中合适的位置。
            j--;  //用j记录最终哨兵要插入的位置。
        }
        arr[j+1] = k; //将哨兵插入到数组合适的位置（形成一个新的排好序的数组）
    }
    for (i=0; i<n; i++) {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
