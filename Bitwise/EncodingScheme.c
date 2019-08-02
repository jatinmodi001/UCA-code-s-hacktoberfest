#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


char* encode(char* input) 
{
    char *s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/0123456789";
    int n = strlen(input);
    int size = n*8;
    int ct = 0,j=0;
    char *output = (char*)calloc((n*4)/3+5,sizeof(char));			 	
    for(int i=0;i<=n;i++)
    {
        if(ct == 0 && i!=n)				
        {

/*	getting character fromed from last 6 bits of ith character ascii value, by right shifting first 2 bits 		*/

            output[j++] = s[(int)input[i] >> 2];		
            ct = 1;
        }
        else if(ct == 1)
       	{
       	
/*	getting character formed from 2 bits of previous character ascii value and 4 bits from the ith character 	*/

            output[j++] = s[((int)input[i-1] & 0X03) << 4  | ((int)input[i] & 0XF0) >> 4];	// & with 00000011, 11110000 so as to get last 2 and first 4
            ct = 2;
        }
        else if(ct == 2)
        {
/*	getting character formed from 4 bits of previous character ascii value and 2 bits of ith character 	*/

            output[j++] = s[((int)input[i-1] & 0X0F ) << 2 | ((int)input[i] & 0XC0) >> 6 ];	// & with 00001111, 11000000 so as to get last 4 and first 2
            ct = 3;
        }
        else if(ct == 3)
        {
/*	getting character formed from 6 bits of previous character	*/

            output[j++] = s[(int)input[i-1] & 0X3F ];		//	& with 00111111 so as to get last 6 bits
            i--;						//	at this stage character input[i] skips if didn't do this (i--).
            ct = 0;
        }
    }
    if(n%3 == 2)
    {
        strcat(output,"=");
    }
    else if(n%3==1)
    {
        strcat(output,"==");
    }
    return output;
}
int main() 
{
    char* input = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",input);

    char *res = encode(input);
    printf("%s\n", res);

    return 0;
}

