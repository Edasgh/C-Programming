// implementation of priority queue using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int pri;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue()
{
    Node *newNode, *temp;
    newNode = (Node *)malloc(sizeof(Node));
   
    printf("Enter a number here : ");
    scanf("%d", &newNode->data);
    printf("Enter the priority no. here : ");
    scanf("%d", &newNode->pri);
    if (front == NULL)
    {
        newNode->next = NULL;
        front = rear = newNode;
    }
    else
    {
       
        if (front->pri > newNode->pri)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            temp = front;
            while (temp->next != NULL)
            {
                if (temp->next->pri > newNode->pri)
                    break;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void dequeue()
{
    Node *temp;
    if (front == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        temp = front;
        front = front->next;
        printf("The dequeued element is %d\n", temp->data);
        free(temp);
    }
}

void display()
{
    Node *temp;
    if (front == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            printf("%d|%d ",temp->data,temp->pri);
            temp = temp->next;
        }
    }
}

void main()
{
    int choice;
    while (1)
    {

        printf("\nSelect:\n1. Enqueue an element,\n2. Dequeue front element,\n3. Display the queue\n4.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
        }
    }
}