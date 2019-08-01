#include<stdio.h>
int SwapAdjacent(int n)
{
    int x = (n >> 1) & 0X55555555;
    int y = (n << 1) & 0XAAAAAAAA;
    
    return x|y;
}
int main()
{
    int n;
    scanf("%d" , &n);

    printf("Number after swapping adjacent bits : %d\n" , SwapAdjacent(n));
}