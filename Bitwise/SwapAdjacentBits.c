#include<stdio.h>
int main()
{
    int n;
    scanf("%d" , &n);

    for(int i = 0 ; i < 32 - __builtin_clz(n) ; i = i+2)
    {
        if( ( (n & (1 << i)) && !( n & (1 << i+1) )) || ( !(n & (1 << i)) && ( n & (1 << i+1) )) )
        {  
            n = n ^ ( 1 << i );
            n = n ^ ( 1 << i+1 );
        }
    }

    printf("Number after swapping adjacent bits : %d\n", n );
}