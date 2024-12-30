#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Stack structure to help in traversal
struct Stack
{
    struct Node *data;
    struct Stack *next;
};

// Function to create a new stack node
struct Stack *newStackNode(struct Node *node)
{
    struct Stack *stackNode = (struct Stack *)malloc(sizeof(struct Stack));
    stackNode->data = node;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct Stack **top, struct Node *node)
{
    struct Stack *stackNode = newStackNode(node);
    stackNode->next = *top;
    *top = stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *top)
{
    return top == NULL;
}

// Function to pop a node from the stack
struct Node *pop(struct Stack **top)
{
    if (isEmpty(*top))
    {
        return NULL;
    }
    struct Stack *temp = *top;
    *top = (*top)->next;
    struct Node *popped = temp->data;
    free(temp);
    return popped;
}

// Function to perform in-order traversal
int *inOrder(struct Node *root, int *returnSize)
{
    struct Stack *stack = NULL;
    struct Node *current = root;
    int *result = (int *)malloc(1000 * sizeof(int)); // Allocate memory for result array
    int index = 0;

    while (!isEmpty(stack) || current != NULL)
    {
        // Reach the leftmost node of the current node
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = pop(&stack);
        result[index++] = current->data; // Add the node data to the result array

        // Visit the right subtree
        current = current->right;
    }

    *returnSize = index;
    return result;
}

// Helper function to create a new tree node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Main function for testing
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int returnSize;
    int *result = inOrder(root, &returnSize);

    printf("In-order traversal: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
