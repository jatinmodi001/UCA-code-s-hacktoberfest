#include<stdio.h>
#include<stdlib.h>
int comp(void *a,void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int n,i,j;
	printf("Enter size of first array\n");
	scanf("%d",&n);
	int arr1[n];
	printf("Enter elements of first array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr1[i]);
	int m;
	printf("Enter size of second array\n");
	scanf("%d",&m);
	int arr2[m];
	printf("Enter elements of second array\n");
	for(i=0;i<m;i++)
		scanf("%d",&arr2[i]);
	qsort(arr1,n,sizeof(arr1[0]),comp);		
	qsort(arr2,m,sizeof(arr2[0]),comp);
	i=0;
	j=0;
	while(i!=n && j!=m)
	{
		if(arr1[i] < arr2[j])
		{
			i++;
		}
		else if(arr1[i] > arr2[j])
		{
			j++;
		}
		else
		{
			printf("%d ",arr2[j]);		
			i++;
			j++;
		}
	}
	return 0;
}
