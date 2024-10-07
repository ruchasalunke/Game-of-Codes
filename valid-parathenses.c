#include <stdio.h>
#include <string.h>
char* isValid(char *st) 
{
    int top = -1;
    char stack[20];
    for (int i=0; i<strlen(st); i++) 
    {
        char current = st[i];
        if(current == '(' || current == '{' || current == '[') 
        {
            top++;
            stack[top] = current;
        } 
        else if(current == ')' || current == '}' || current == ']') 
        {
            if (top == -1) 
                return "FALSE";
            char last = stack[top];
            top--;
            if ((current == ')' && last != '(') || (current == '}' && last != '{') || (current == ']' && last != '['))
                return "FALSE";
        }
    }
    return (top == -1)?"TRUE":"FALSE";
}
int main()
{
    char s[20];
    scanf("%19s", s);
    printf("%s\n", isValid(s));
    return 0;
}
