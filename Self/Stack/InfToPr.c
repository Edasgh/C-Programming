// c program to convert an infix expression into a prefix expression using stack
// gcc InfToPr.c -o a
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char Stack[100];
int top = -1;

char str[] = "K+L-M*N+(O^P)*W/U/V*T+Q";

void reverse(char *s)
{
    //reverse the brackets too
    int n = strlen(s);
    char temp[n + 1];
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            temp[n - 1 - i] = ')';
        else if (s[i] == ')')
            temp[n - 1 - i] = '(';
        else
            temp[n - 1 - i] = s[i];
    }
    temp[n] = '\0';
    strcpy(s, temp);
}

char Pop()
{
    if (top == -1)
    {
        printf("\n");
    }
    else
    {
        return Stack[top--];
    }
}

void Push(char c)
{
    int n = strlen(str);
    if (top == n - 1)
    {
        printf("\n");
    }
    else
    {
        top++;
        Stack[top] = c;
    }
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int isOp(char c)
{
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'||isalnum(c))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixToPrefix()
{
    reverse(str);
    int n = strlen(str);

    char res[n + 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (isOp(str[i]))
            res[j++] = str[i];
        else if (str[i] == '(')
            Push('(');
        else if (str[i] == ')')
        {
            while (top != -1 && Stack[top] != '(')
            {
                res[j++] = Pop();
            }
            Pop();
        }
        else
        {
            while (top != -1 && prec(str[i]) < prec(Stack[top]))
            {
                res[j++] = Pop();
            }

            if (top != -1 && prec(str[i]) == prec(Stack[top]) && str[i] == '^')
            {
                while (top != -1 && prec(str[i]) == prec(Stack[top]) && str[i] == '^')
                {
                    res[j++] = Pop();
                }
            }
            Push(str[i]);
        }
    }

    while (top != -1)
    {
        res[j++] = Pop();
    }
    res[j] = '\0';
    reverse(res);
    printf("%s", res);
}

void main()
{
    infixToPrefix();
}