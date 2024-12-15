// C program to evaluate a postfix expression
// gcc EvalPostfx.c -o a
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int Stack[MAX];
int top = -1;

// Check if the character is an alphabetic operand
int isAlphaOperand(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Check if the character is a numeric operand
int isOperand(char c)
{
    return c >= '0' && c <= '9';
}

// Check if the character is an operator
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Push an element onto the stack
void push(int item)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    Stack[++top] = item;
}

// Pop an element from the stack
int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return Stack[top--];
}

// Evaluate a postfix expression
int eval(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        // Skip whitespace
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        // If the character is a digit, parse the number
        if (isdigit(exp[i]))
        {
            int num = 0;
            //to handle the cases of two digit numbers
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else if (isOperator(exp[i]))
        { // If the character is an operator
            int op2 = pop();
            int op1 = pop();
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
            i++;
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
    char postfix[] = "2 3 4 * + 16 2 3 ^ / -";
    int res = eval(postfix);
    printf("Result = %d\n", res);
    return 0;
}
