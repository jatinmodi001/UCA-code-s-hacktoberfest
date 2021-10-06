#include<stdio.h>
#include<stdlib.h>
int comp(const void* a,const void* b)
{
	return *(int *)a - *(int *)b;
}
int BinarySearch(int arr[],int n,int a)
{
	int l = 0,r = n-1;
	int mid;
	// find mid element and check
	while(l<=r)
	{
		mid = (l+r)/2;
		// COMPARE ELEMENT
		if(a > arr[mid])
		{
			l = mid + 1;
		}
		else if(a < arr[mid])
		{
			r = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++) 
		scanf("%d",&arr[i]);
	int k;
	scanf("%d",&k);
	qsort(arr,n,sizeof(arr[0]),comp);
	for(int i=0;i<n-1;i++)
	{
		int a = BinarySearch(arr,n,arr[i]+k);
		if(a!=-1)
		{
			printf("%d %d\n",arr[i],arr[a]);
			break;
		}
	}
	return 0;
}
