#include<stdio.h>
int main()
{
    int n;
    scanf("%d" , &n);

    int i ;
    scanf("%d" , &i);

    n = n & ~ (1<<(i-1));

    printf("Number after setting ith bit to zero : %d\n",n);
}