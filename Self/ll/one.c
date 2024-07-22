#include <stdio.h>
#include <stdlib.h>
// gcc one.c -o a
//.\a.exe

struct node
{
    int data;
    struct node *next;
};

void createNode(struct node **head, struct node **temp, struct node **newNode)
{
    *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &((*newNode)->data));
    (*newNode)->next = NULL;

    if (*head == NULL)
    {
        *head = *newNode;
    }
    else
    {
        (*temp)->next = *newNode;
    }

    *temp = *newNode;
}

void traverseList(struct node *head, struct node **temp)
{
    printf("\nPrinting the linked list : \n");
    int count = 0;
    *temp = head;
    while (*temp != NULL)
    {
        printf(" %d ", (*temp)->data);
        *temp = (*temp)->next;
        count++;
    }
    printf("\nThe length of the linked list is: %d\n", count);
}

void insertAtStart(struct node **head, struct node **temp, struct node **newNode)
{
    *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value : ");
    scanf("%d", &((*newNode)->data));
    (*newNode)->next = *head;

    *head = *newNode;
}

void insertAtEnd(struct node **head, struct node **temp, struct node **newNode)
{
    *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value : ");
    scanf("%d", &((*newNode)->data));
    (*newNode)->next = NULL;
    *temp = *head;
    while ((*temp)->next != NULL)
    {
        *temp = (*temp)->next;
    }
    (*temp)->next = *newNode;
}

void insertAtPos(int pos, struct node **head, struct node **temp, struct node **newNode)
{
    *temp = *head;
    int i = 1;
    while (i < pos)
    {
        *temp = (*temp)->next;
        i++;
    }
    *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value : ");
    scanf("%d", &((*newNode)->data));
    (*newNode)->next = (*temp)->next;
    (*temp)->next = *newNode;
}

void main()
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

addNode:
    createNode(&head, &temp, &newNode);
    int val;
    printf("\nCreate another node ?\n 1.Yes ,2.NO  :  ");
    scanf("%d", &val);
    if (val == 1)
    {
        goto addNode;
    }
    else
    {
        goto printVal;
    }

printVal:
    traverseList(head, &temp);

    // **ptr and &ptr is used to modify the original values in 'main'
}
