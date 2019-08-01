#include<stdio.h>
int main()
{
	int n;
	printf("Enter the size of left and right array\n");
	scanf("%d",&n);
	int size = 0;
	int left[n],right[n];
	for(int i=0;i<n;i++)
		scanf("%d",&left[i]);
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&right[i]);
		if(size < right[i])
			size = right[i];
	}
	size ++;
	int arr[size];
	for(int i=0;i<size;i++)
		arr[i] = 0;
	int a = 0;
	while(a!=n)
	{
		for(int i = left[a] ; i <= right[a] ; i++)
		{
			arr[i]++;
		}
		a++;
	}
	int max = 0;
	for(int i=0;i<size;i++)
	{
		if(arr[max] < arr[i])
			max = i;		
	}
	printf("%d\n",max);
}
