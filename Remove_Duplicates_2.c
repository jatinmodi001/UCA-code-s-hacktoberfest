#include<stdio.h>
int remove_duplicates_2(int arr[],int n)
{
	int j = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] == arr[i+1] && arr[i] == arr[i+2])
			continue;
		arr[j] = arr[i];
		j++;
	}
	return j;
}
int main()
{
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements\n");
	for(int i = 0 ; i < n ; i++)	
		scanf("%d",&arr[i]);
	n = remove_duplicates_2(arr,n);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
