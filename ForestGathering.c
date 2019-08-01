#include<stdio.h>

long findMonths(long arr[][2],long n,long long int w,long long int L)
{
	long long int l = 0,r = 1000000000000000000;			// as per constraints r is taken as 10^18 or we can use r = w
	long long int sum = 0;
	LOOP:
	while(l < r )
	{
		long long int mid = (l+r)/2;
		sum = 0;
		for(long i = 0; i < n ; i++)
		{
			if( (arr[i][0] + arr[i][1]*mid) >= L)
			{
				sum += arr[i][0] + arr[i][1]*mid;
				if(sum >= w )
				{
					r = mid;
					goto LOOP;
				}
			}
		}
		l = mid + 1;
	}
	return r;
}
int main()
{
    long n;
    long long int w,l;
    scanf("%ld%lld%lld",&n,&w,&l);					// scanning number of trees , height order, minimum required height for cutting
    long arr[n][2];									// taking the 2D array for height and rate of growth.

    for(long i=0;i<n;i++)
        for(int j=0;j<2;j++)
            scanf("%ld",&arr[i][j]);						
    
    printf("%ld\n",findMonths(arr,n,w,l));						// calling function findMonths which will return the months required to wait.
}
