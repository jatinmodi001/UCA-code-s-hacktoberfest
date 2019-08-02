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
            output[j++] = s[(int)input[i] >> 2];
            ct = 1;
        }
        else if(ct == 1)
        {
            output[j++] = s[((int)input[i-1] & 0X03) << 4  | ((int)input[i] & 0XF0) >> 4];
            ct = 2;
        }
        else if(ct == 2)
        {
            output[j++] = s[((int)input[i-1] & 0X0F ) << 2 | ((int)input[i] & 0XC0) >> 6 ];
            ct = 3;
        }
        else if(ct == 3)
        {
            output[j++] = s[(int)input[i-1] & 0X3F ];
            i--;
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
int main() {
    char *output_path = getenv("OUTPUT_PATH");
    FILE *f;
    if (output_path != NULL) {
        f = fopen(output_path, "w");
    }
    else {
        f = stdout;
    }

    char* res;
    char* input;
    input = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",input);

    res = encode(input);
    fprintf(f, "%s\n", res);

    fclose(f);
    return 0;
}

