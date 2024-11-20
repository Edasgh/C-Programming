#include <stdio.h>
#include <stdlib.h>

//implementation of queue using linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front =NULL, *rear=NULL;


void enqueue(){
    Node *newNode;
    newNode = (Node *) malloc(sizeof(Node));
    printf("Enter a number here : ");
    scanf("%d",&(newNode->data));
    newNode->next = 0;
    if(front==NULL && rear ==NULL)
    {
        front=rear=newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    
}

void dequeue()
{
    Node *temp;
    if(front==NULL && rear ==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        temp = front;
        printf("The dequeued element is %d\n",temp->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    Node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void Peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The data at front is %d\n",front->data);
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\nSelect an option to perform :\n1.Add an element in the queue,\n2.Delete the front element from queue,\n3.Traverse the queue,\n4.View the front element of the queue,\n5.exit\n");
        scanf("%d",&choice);
        switch(choice)
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
            Peek();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid option!");
        }
    }
}