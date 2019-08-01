#include<stdio.h>
int checkPattern(int n)
{
    int count = __builtin_clz(n);

    int x = n & 0XAAAAAAAA & ~(-1 << (32-count));
    int y = n & 0X55555555 & ~(-1 << (32-count));

    if(x == 0 || y == 0)
        return 1;
    
    return 0;
}
int main()
{
    int n;
    scanf("%d" , &n);

    if(checkPattern(n))
        printf("Yes\n");
    else
        printf("No\n");
}