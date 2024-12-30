#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Stack implementation
typedef struct Stack
{
    Node **arr;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (Node **)malloc(sizeof(Node *) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, Node *node)
{
    if (stack->top == stack->capacity - 1)
    {
        stack->capacity *= 2;
        stack->arr = (Node **)realloc(stack->arr, sizeof(Node *) * stack->capacity);
    }
    stack->arr[++stack->top] = node;
}

Node *pop(Stack *stack)
{
    return stack->arr[stack->top--];
}

Node *peek(Stack *stack)
{
    return stack->arr[stack->top];
}

void freeStack(Stack *stack)
{
    free(stack->arr);
    free(stack);
}

// Function to reverse an array
void reverseArray(int *arr, int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Postorder traversal function
int *postOrder(Node *root, int *returnSize)
{
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }

    int capacity = 100;
    int *res = (int *)malloc(sizeof(int) * capacity);
    Stack *stack = createStack(100);

    push(stack, root);
    while (!isEmpty(stack))
    {
        Node *temp = pop(stack);
        if (*returnSize == capacity)
        {
            capacity *= 2;
            res = (int *)realloc(res, sizeof(int) * capacity);
        }
        res[(*returnSize)++] = temp->data;

        if (temp->left)
        {
            push(stack, temp->left);
        }
        if (temp->right)
        {
            push(stack, temp->right);
        }
    }

    reverseArray(res, *returnSize);
    freeStack(stack);
    return res;
}

// Helper function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Example usage
int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int returnSize;
    int *result = postOrder(root, &returnSize);

    printf("Postorder Traversal: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}