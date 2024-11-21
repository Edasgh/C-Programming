#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node ;

Node *front = NULL, *rear = NULL;

void enqueue()
{
Node *newNode;
newNode = (Node *) malloc(sizeof(Node));
printf("Enter a number here : ");
scanf("%d",&(newNode->data));
if(front==NULL)
{
    front = newNode;
    
}else
{
    rear->next = newNode;
}
rear = newNode;
rear->next = front;
}

void dequeue()
{
    Node *temp;
    if(front==NULL && rear == NULL)
    {
        printf("The queue is empty\n");
    }
    else if(front==rear)
    {
        temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else
    {
        temp = front;
        printf("The dequeued element is %d\n",temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
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
        printf("The front element is %d\n",front->data);
    }
    }

void display()
{
 Node *temp;
 if(front==NULL && rear==NULL)
 {
    printf("The queue is empty\n");
 }
 else
 {
    temp = front;

    while (temp->next != front)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
 }
}

void main()
{
    int choice;
     while(1)
     {
         printf("\nSelect an option to perform :\n1. Enqueue an element in the queue,\n2. Dequeue the front element from the queue\n3. Display the queue,\n4. View the front element of the queue\n5.exit\n");
         scanf("%d", &choice);
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
            printf("Invalid option\n");
         }
     }
}