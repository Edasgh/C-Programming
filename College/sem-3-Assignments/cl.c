#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int getLength(Node **head)
{
    int length = 0;
    Node *t = *head;
    while (t != NULL)
    {
        length++;
        t = t->next;
    }
    return length;
}

void createNode(Node **head, Node **tail)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data to insert: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void insAtBeg(Node **head, Node **tail)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data to insert: ");
    scanf("%d", &(newNode->data));
    newNode->next = *head;
    *head = newNode;
    if (*tail == NULL)
    {
        *tail = newNode;
    }
}

void insAtEnd(Node **head, Node **tail)
{
    createNode(head, tail);
}

void insAtAnyPos(Node **head, Node **tail)
{
    int length = getLength(head);
    int pos;
    printf("Enter the position to insert data: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > length)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 0)
    {
        insAtBeg(head, tail);
    }
    else if (pos == length)
    {
        insAtEnd(head, tail);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data to insert: ");
        scanf("%d", &(newNode->data));

        Node *t = *head;
        for (int i = 0; i < pos - 1; i++)
        {
            t = t->next;
        }
        newNode->next = t->next;
        t->next = newNode;
    }
}

void delFromBeg(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty!\n");
        return;
    }

    Node *temp = *head;
    printf("Deleted element: %d\n", temp->data);
    *head = (*head)->next;
    if (*head == NULL)
    {
        *tail = NULL;
    }
    free(temp);
}

void delFromEnd(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty!\n");
        return;
    }

    if (*head == *tail)
    {
        printf("Deleted element: %d\n", (*head)->data);
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        Node *t = *head;
        while (t->next != *tail)
        {
            t = t->next;
        }
        printf("Deleted element: %d\n", (*tail)->data);
        free(*tail);
        *tail = t;
        t->next = NULL;
    }
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty!\n");
    }
    else
    {
        Node *t = head;
        while (t != NULL)
        {
            printf("%d -> ", t->data);
            t = t->next;
        }
        printf("NULL\n");
    }
}

void main()
{
    Node *head = NULL, *tail = NULL;
    int ch;

    while (1)
    {
        printf("\nOptions:\n");
        printf("1. Create a node\n");
        printf("2. Insert a node\n");
        printf("3. Delete a node\n");
        printf("4. Display the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            createNode(&head, &tail);
            break;
        case 2:
            insAtAnyPos(&head, &tail);
            break;
        case 3:
            delFromBeg(&head, &tail);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid option! Please try again.\n");
        }
    }
}
