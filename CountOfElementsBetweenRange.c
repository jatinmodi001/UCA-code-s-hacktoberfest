#include<stdio.h>
#include<stdlib.h>
int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int LowerBound(int arr[],int n,int min)
{
/*	Finding the lower bound of min in arrray using Binary Search	*/

	int l = 0,r = n-1,mid ;
	while( l < r )
	{
		mid = (l+r)/2;
		if( arr[mid] >= min)
		{
			r = mid;
		}
		else if( arr[mid] < min)
		{
			l = mid + 1;
		}
	}
	return r;
}
int UpperBound(int arr[],int n, int max)
{
/*	Finding the upper bound of max value in array using Binary Search	*/
	
	int l = 0, r = n-1, mid;
	while( l < r )
	{
		mid = (l+r)/2;
		if(arr[mid] <= max)
		{
			l = mid + 1;
		}
		else if(arr[mid] > max)
		{
			r = mid;
		}
	}
	return r;
}
int main()
{
	int n,min,max;
	printf("Enter the number of marks\n");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter marks\n");
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&arr[i]);
		
	printf("Enter lower and upper value of marks\n");
	scanf("%d%d",&min,&max);
	
	qsort(arr,n,sizeof(arr[0]),comp);			// sorting array using qsort

	int lower = LowerBound(arr,n,min);
	int upper = UpperBound(arr,n,max);
	
	printf("%d\n%d\n",upper,lower);
}
