// C program to evaluate a prefix expression
// gcc EvalPrefx.c -o a
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int Stack[MAX];
int top = -1;

// Push an element onto the stack
void push(int num)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    Stack[++top] = num;
}

// Pop an element from the stack
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return Stack[top--];
}

// Check if the character is an operator
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Evaluate a prefix expression
int eval(char *exp)
{
    int n = strlen(exp);
    int i = n - 1;

    while (i >= 0)
    {
        // Skip whitespace
        if (exp[i] == ' ')
        {
            i--;
            continue;
        }

        // If the character is a digit, parse the number
        if (isdigit(exp[i]))
        {
            int num = 0;
            int place = 1;

            // Handle multi-digit numbers
            while (i >= 0 && isdigit(exp[i]))
            {
                num = (exp[i] - '0') * place + num;
                place *= 10;
                i--;
            }
            push(num);
        }
        else if (isOperator(exp[i]))
        { // If the character is an operator
            int op1 = pop();
            int op2 = pop();
            int res;

            switch (exp[i])
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                if (op2 == 0)
                {
                    printf("Division by zero error\n");
                    exit(1);
                }
                res = op1 / op2;
                break;
            case '^':
                res = 1;
                for (int k = 0; k < op2; k++)
                {
                    res *= op1;
                }
                break;
            default:
                printf("Invalid operator\n");
                exit(1);
            }
            push(res);
            i--;
        }
        else
        {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    return pop();
}

int main()
{
    char prefx[] = "- + 2 * 3 4 / 16 ^ 2 3";
    int result = eval(prefx);
    printf("Result = %d\n", result);
    return 0;
}
