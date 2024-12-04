// implementation of queue using array in C
#include <stdio.h>
#include <stdlib.h>

int Queue[100];
int front = -1, rear = -1;

void enqueue(int N)
{
    int num;
    if (rear < N - 1)
    {
        printf("Enter the data to insert : ");
        scanf("%d", &num);
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        Queue[rear] = num;
    }
    else
    {
        printf("Overflow condition\n");
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow condition\n");
    }
    else if (front == rear)
    {
        printf("The dequeued element is %d\n", Queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("The dequeued element is %d\n", Queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", Queue[i]);
        }
    }
}

void Peek()
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The front element is %d\n", Queue[front]);
    }
}

void main()
{
    int size;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    int choice;
    while (1)
    {
        printf("\nSelect an option to perform :\n1.Add an element in the queue,\n2.Delete the front element from queue,\n3.Traverse the queue,\n4.View the front element of the queue,\n5.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(size);
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