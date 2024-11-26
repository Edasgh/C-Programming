// circular queue in C using array
#include <stdio.h>
#include <stdlib.h>

int q[50];
int front =-1;
int rear =-1;

int isFull(int size)
{
    int result=0;
    if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
    {
        result = 1;
    }
        return result;
}

int isEmpty()
{
    int result = 0;
    if(front==-1 && rear==-1)
    {
        result = 1;
    }
    return result;
}

void enqueue (int size)
{
    int full,num;
    full = isFull(size);
    if(full)
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("Enter a number here : ");
        scanf("%d", &num);
        if(front==-1) front++;
        rear = (rear+1)%size;
        q[rear]=num;
    }
}

void dequeue(int size)
{
    int empty;
    empty = isEmpty();
    if(empty)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The dequeued element is : %d\n", q[front]);
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front+1)%size;
        }
    }
}

void display( int size)
{
    int empty, i;
    empty = isEmpty();
    if(empty)
    {
        printf("The queue is empty\n");
    }
    else
    {
        if(rear<front)
        {
            for(i=front;i<size;i++)
            {
                printf("%d ",q[i]);
            }
            for(i=0;i<=rear;i++)
            {
                printf("%d ",q[i]);
            }
        }
        else
        {
            for(i=front;i<=rear;i++)
            {
                printf("%d ",q[i]);
            }
        }

    }
}

void Peek(int size)
{
    int empty;
    empty = isEmpty();
    if(empty)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The front element is %d\n",q[front]);
    }

}

void main()
{
    int size;
    printf("Enter the size of the queue : ");
    scanf("%d",&size);
    int choice;
    while(1)
    {
        printf("\nSelect an option to perform :\n1. Enqueue an element in the queue,\n2. Dequeue the front element from the queue\n3. Display the queue,\n4. View the front element of the queue\n5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
         enqueue(size);
         break;
         case 2:
         dequeue(size);
         break;
         case 3:
         display(size);
         break;
         case 4:
         Peek(size);
         break;
         case 5:
         exit(0);
         break;
         default:
         printf("Invalid option\n");
        }
    }
}