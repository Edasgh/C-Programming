#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// EvalInfx.c
#define MAX 100

// Stacks
int values[MAX], valuesTop = -1;
char ops[MAX];
int opsTop = -1;

// Push to values stack
void valuesPush(int num)
{
    if (valuesTop >= MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    values[++valuesTop] = num;
}

// Pop from values stack
int valuesPop()
{
    if (valuesTop == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return values[valuesTop--];
}

// Push to operators stack
void opsPush(char c)
{
    if (opsTop >= MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    ops[++opsTop] = c;
}

// Pop from operators stack
char opsPop()
{
    if (opsTop == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return ops[opsTop--];
}

// Check if character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Operator precedence
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Function to apply an operator
int applyOperator(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("\nDivision by 0 error\n");
            exit(1);
        }
        return a / b;
    case '^':
    {
        int res = 1;
        for (int i = 0; i < b; i++)
            res *= a;
        return res;
    }
    }
    return 0;
}

// Function to evaluate an infix expression
int evalInfix(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
    {
        // Ignore spaces
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        // If character is a digit, extract full number
        if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            valuesPush(num);
        }
        // If opening parenthesis
        else if (exp[i] == '(')
        {
            opsPush(exp[i]);
            i++;
        }
        // If closing parenthesis, solve entire bracket
        else if (exp[i] == ')')
        {
            while (opsTop != -1 && ops[opsTop] != '(')
            {
                int b = valuesPop();
                int a = valuesPop();
                char op = opsPop();
                valuesPush(applyOperator(a, b, op));
            }
            // Pop the '(' from the operator stack
            if (opsTop != -1)
                opsPop();
            i++;
        }
        // If character is an operator
        else if (isOperator(exp[i]))
        {
            // While the operator at the top has higher or equal precedence, apply it
            while (opsTop != -1 && prec(ops[opsTop]) >= prec(exp[i]))
            {
                int b = valuesPop();
                int a = valuesPop();
                char op = opsPop();
                valuesPush(applyOperator(a, b, op));
            }
            opsPush(exp[i]);
            i++;
        }
        else
        {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    // Process remaining operators in the stack
    while (opsTop != -1)
    {
        int b = valuesPop();
        int a = valuesPop();
        char op = opsPop();
        valuesPush(applyOperator(a, b, op));
    }

    return valuesPop(); // Final result
}

// Main function
int main()
{
    char expression[] = "3 + 5 * (2 - 6)";
    int result = evalInfix(expression);
    printf("Result = %d\n", result);
    return 0;
}
