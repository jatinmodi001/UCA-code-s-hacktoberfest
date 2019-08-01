#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d %d %d" , &n , &i , &j);

    if( ( (n & (1 << i-1)) && !( n & (1 << j-1) )) || ( !(n & (1 << i-1)) && ( n & (1 << j-1) )) )
    {
        n = n ^ ( 1 << i-1 );
        n = n ^ ( 1 << j-1 );
    }

    printf("Number after swapping ith and jth bit : %d\n" , n);
}