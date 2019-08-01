#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int ct = 1;
	int dir = 0,top = 0,right = n-1,bottom = n-1, left = 0;
	while(top<=bottom && left<=right)
	{
		if(dir == 0)
		{
			for(int i = left;i<=right; i++)
			{
				arr[top][i] = ct++;
			}
			dir = 1;
			top++;
		}
		else if(dir == 1)
		{
			for(int i = top;i<=bottom;i++)
			{
				arr[i][right] = ct++;
			}
			dir = 2;
			right--;
		}
		else if(dir == 2)
		{
			for(int i = right; i>= left ;i--)
			{
				arr[bottom][i] = ct++;
			}
			dir = 3;
			bottom--;
		}
		else
		{
			for(int i = bottom; i>= top; i--)
			{
				arr[i][left] = ct++;
			}
			dir = 0;
			left++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}
