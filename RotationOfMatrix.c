#include<stdio.h>
int main()
{
	printf("Enter the size of array\n");
	int n;
	scanf("%d",&n);
	printf("Enter elements\n");
	int arr[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	for(int i=0;i<n/2;i++)
	{
		for(int j=i;j<n-1-i;j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[n-1-j][i];
			arr[n-1-j][i] = arr[n-1-i][n-1-j];
			arr[n-1-i][n-1-j] = arr[j][n-1-i];
			arr[j][n-1-i] = temp;	
		}
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}
