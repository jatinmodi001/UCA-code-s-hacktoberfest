#include<stdio.h>
void swap(int *a,int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
int main()
{
	int n;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements\n",n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&arr[i]);
	int k;
	printf("Enter number of groups\n");
	scanf("%d",&k);
	//reverse elements in group
	for(int i= 0 ; i < n ;i = i + k)
	{
		if(i + k <= n)
		{
			for(int j = 0 ; j < k/2 ; j++)
				swap(&arr[i+j],&arr[k-1-j+i]);
		}		
		else
		{
			for(int j = 0 ; j < (n-i)/2; j++)
			{
				swap(&arr[i+j],&arr[n-1-j]);
			}
		}

	}
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
