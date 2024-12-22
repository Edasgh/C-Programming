// gcc queueL.c -o a
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;
// insertion from rear
// deletion from front

void enqueue()
{
    // from rear
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a number to insert : ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (rear == NULL && front == NULL)
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }

    rear = newNode;
}

int dequeue()
{
    Node *t;
    if (front == NULL && rear == NULL)
    {
        printf("\nThe Queue is empty\n");
        return -1;
    }
    else
    {
        t = front;
        front = front->next;
        printf("\nThe dequeued element is %d\n", t->data);
        int n = t->data;
        free(t);
        return n;
    }
}

void Peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nThe Queue is empty\n");
    }
    else
    {
        printf("\nThe front element is %d\n", front->data);
    }
}

void Traverse()
{
    Node *t;
    if (front == NULL && rear == NULL)
    {
        printf("\nThe Queue is empty\n");
    }
    else
    {
        t = front;
        while (t != NULL)
        {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    printf("\nQueue Using Linked List\n");

    while (1)
    {
        printf("Select an option to perform :\n1.Insert an element in the queue,\n2.Delete the front element of the queue,\n3.View the front element of the queue,\n4.Traverse the queue,\n5.Exit\nSelect :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Traverse();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid choice\n");
        }
    }
}