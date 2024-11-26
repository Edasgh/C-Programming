// implementation of priority queue using array
#include <stdio.h>
#include <stdlib.h>
typedef struct PriorQ
{
    int data;
    int pri;
} prQ;

prQ pq[100];
int front = -1, rear = -1;

void enqueue(int size)
{
    int num, pri, i, index;
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("Enter a number here : ");
        scanf("%d", &num);
        printf("Enter the priority no. here : ");
        scanf("%d", &pri);
        pq[rear].data = num;
        pq[rear].pri = pri;
    }
    else if (rear >= size - 1)
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("Enter a number here : ");
        scanf("%d", &num);
        printf("Enter the priority no. here : ");
        scanf("%d", &pri);
        for (i = 0; i <= rear; i++)
        {
            if (pq[i].pri > pri)
            {
                break;
            }
        }
        rear++;
        index = rear;
        while (index > i)
        {
            pq[index] = pq[index - 1];
            index--;
        }
        pq[i].pri = pri;
        pq[i].data = num;
    }
}

void dequeue(int size)
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty\n");
    }
    else if (front == rear || front == size - 1)
    {
        printf("The dequeued element is %d \n", pq[front].data);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("The dequeued element is %d \n", pq[front].data);
        front++;
    }
}

void display(int size)
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
            printf("%d|%d ", pq[i].data, pq[i].pri);
        }
    }
}

void main()
{
    int size, choice;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    while (1)
    {

        printf("\nSelect:\n1. Enqueue an element,\n2. Dequeue front element,\n3. Display the queue\n4.exit\n");
        scanf("%d", &choice);
        switch (choice)
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
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
        }
    }
}