// c code to convert an infix expression into a postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Stack[50];
int top = -1;

int prec(char c)
{
    int prec;
    if (c == '^')
    {
        prec = 3;
    }
    else if (c == '*' || c == '/')
    {
        prec = 2;
    }
    else if (c == '+' || c == '-')
    {
        prec = 1;
    }
    else
    {
        return -1;
    }

    return prec;
}

void infixToPostfix(char *exp)
{
    int n = strlen(exp);
    char res[n + 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        char c = exp[i];
        if (isalnum(c))
            res[j++] = c; // isalnum returns true if the character is an alphabet or an integer (0-9)
        else if (c == '(')
        {
            Stack[++top] = '(';
        }
        else if (c == ')')
        {
            while (top != -1 && Stack[top] != '(')
            {
                res[j++] = Stack[top--];
            }
            top--;
        }
        else
        {

            while (top != -1 && (prec(c) < prec(Stack[top])) || (prec(c) == prec(Stack[top])))
            {
                res[j++] = Stack[top--];
            }
            Stack[++top] = c;
        }
    }

    while (top != -1)
    {
        res[j++] = Stack[top--];
    }

    res[j] = '\0';
    printf("%s\n", res);
}

void main()
{
    char infix[] = "K+L-M*N+(O^P)*W/U/V*T+Q";
    infixToPostfix(infix);
}