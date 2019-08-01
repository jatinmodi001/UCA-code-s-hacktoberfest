#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int comp(const void *a,const void* b)
{
	return (*(const int *)a - *(const int *)b);
}
int max(int a,int b,int c)
{
	if(a>=b && a>=c)
		return a;
	if(b>=a && b>=c)
		return b;
	return c;
}
int min(int a,int b,int c)
{
	if(a<=b && a<=c)
		return a;
	if(b<=a && b<=c)
		return b;
	return c;
}
void Minimize(int arr1[],int arr2[],int arr3[],int size1,int size2,int size3)
{
	int i=0,j=0,k=0;
	int minimum=99999;
	int a=0,b=0,c=0;
	while(i<size1 && j<size2 && k<size3)
	{
		int m = max(arr1[i],arr2[j],arr3[k]);				// Finding tha max value
		int n = min(arr1[i],arr2[j],arr3[k]);				// Finding tha min value
		if(abs(m - n) < minimum)
		{
			minimum = abs(m-n);
			a = i;
			b = j;
			c = k;
		}
		if(n == arr1[i])
			i++;
		else if(n == arr2[j])
			j++;
		else
			k++;
	}
	printf("%d %d %d\n",arr1[a],arr2[b],arr3[c]);
}
int main()
{
	int n,m,k;
	printf("Enter the size of first array\n");
	scanf("%d",&n);
	printf("Enter elements of first array\n");
	int arr1[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr1[i]);
	printf("Enter the size of second array\n");
	scanf("%d",&m);
	printf("Enter elements of second array\n");
	int arr2[m];
	for(int i=0;i<m;i++)
		scanf("%d",&arr2[i]);
	printf("Enter the size of third array\n");
	scanf("%d",&k);
	printf("Enter elements of third array\n");
	int arr3[k];
	for(int i=0;i<k;i++)
		scanf("%d",&arr3[i]);
	qsort(arr1,n,sizeof(arr1[0]),comp);		// sorting arrays
	qsort(arr2,m,sizeof(arr2[0]),comp);
	qsort(arr3,k,sizeof(arr3[0]),comp);
	Minimize(arr1,arr2,arr3,n,m,k);
	return 0;
}
