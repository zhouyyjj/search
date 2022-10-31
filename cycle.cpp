//循环有序数组查找某个数
#include<stdio.h>
int find(int ls[], int target)
{
	int low,high;
    low = 0;
    high = length(ls)-1;
    while(low <= high)
	{
        mid = (low+high)/2;
        if(ls[mid] == target)
		{
            return mid;
		}
        if(ls[mid] >= ls[low])
		{
            if(ls[low] <= target&& target< ls[mid])
			{
                high = mid-1;
			}
            else
			{
                low = mid+1;
			}
		}
   
        else
		{
            if(ls[mid] < target && target<= ls[high])
			{
                low = mid+1;
			}
            else
			{
                high = mid-1;
			}
		}
	}
    return -1;
}

int main()
{
	ls[]={1,5,8,9,22,45,55,68};
	print(find(ls[], target));
}
