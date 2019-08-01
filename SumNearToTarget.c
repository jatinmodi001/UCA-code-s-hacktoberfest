#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int target,n,i,j=1,k=0,sum=-999999,dist =99999;
	scanf("%d",&n);					// scannning size of array
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(arr[0]),comp);		//sort array
	scanf("%d",&target);				//scanning the target number
	k = n-1;
	int a,b,c;
	for(i=0;i<n-2;i++)
	{
		j = i+1;k = n-1;
		while(j < k)
		{
			a=i;b=j;c=k;
			sum = arr[i] + arr[j] + arr[k];
			if(sum < target && abs(target-sum)<dist)
			{
				dist = abs(abs(sum)-abs(target));
				j++;
			}		
			else if(sum > target && abs(sum-target)<dist)
			{
				dist = abs(abs(sum)-abs(target));
				k--;
			}
			else
				break;
		}
	}
	printf("%d %d %d\nSum : %d\n",arr[a],arr[b],arr[c],sum);
	return 0;
}
