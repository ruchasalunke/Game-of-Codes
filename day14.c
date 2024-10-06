#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() 
{
    char s[20];
    scanf("%19s",s);
    for(int i=0;i<strlen(s);i++)
    {
        int temp=1;
        for(int j=0;j<strlen(s);j++)
        {
            if((i!=j) && (s[i]==s[j]))
            {
                temp=0;
                break;
            }
        }
        if(temp)
        {
            putchar(s[i]);
            break;
        }
    }
    return 0;
}
