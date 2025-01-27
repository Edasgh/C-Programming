#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} Node;

void createBST(Node **root, int num)
{
    Node *left, *right;
    // 13 15 3 6 8 23 45 9 20 24 26
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->left = newNode->right = NULL;
        *root = newNode;
    }
    else
    {
        
    }
}

void main()
{
    int n;
    printf("Enter the no. of input size : ");
    scanf("%d", &n);
    int arr[n];
    printf("Now enter the inputs to create a BST : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Node *root = NULL;
}