#include<stdio.h>
int find(int arr[],int n,int count_zero,int *min)
{
	int l = 0,max = 0,a = 0,b = 0,r = 0,cz=0;
	while(r < n )
	{
 		if(arr[r] == 1)
			r++;
		else if(arr[r] == 0 && cz < count_zero)
		{
			r++;
			cz++;
		}
		else
		{
			while(arr[l]!=0)
				l++;
			l++;
			if(cz > count_zero)
				cz--;
		}
		if(r-l > max)
		{
			max = r-l;
			a = l;
			b = r;
		}
		if(a<b)
		{
			b = a;
		}
	}
	*min = a;
	return b;
}
int main()
{
	int n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int count_zero;
	printf("Enter count of zeros\n");
	scanf("%d",&count_zero);
	int left = 0;
	int right = find(arr,n,count_zero,&left);
	for(int i=left;i<right;i++)
	{
		printf("%d ",i);
	}
	return 0;
}
