#include<stdio.h>
int main()
{
    int n;
    scanf("%d" , &n);           // scanning number

    int i ;
    scanf("%d" , &i);           // scanning the bit number
    
    n = n ^ (1<<(i-1));       // fliping the ith bit

    printf("Number after replacing ith bit %d\n",n);

}