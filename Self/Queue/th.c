// implementation of queue using stack
// Using array
#include <stdio.h>
#include <stdlib.h>
int s1[100], s2[100];
// s1 is the queue here
int top1 = -1, top2 = -1;
int front = -1, rear = -1;
int Pop1()
{
    if (top1 == -1)
    {
        printf("Underflow condition\n");
        return -1;
    }
    else
    {
        return s1[top1--];
    }
}
int Pop2()
{
    if (top2 == -1)
    {
        printf("Underflow condition\n");
        return -1;
    }
    else
    {
        return s2[top2--];
    }
}

void Push1(int num, int size)
{
    if (top1 == size - 1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        s1[++top1] = num;
        rear = top1; // Update rear
        if (front == -1)
            front = 0; // Initialize front if queue was empty
    }
}
void Push2(int num, int size)
{

    if (top2 == size - 1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        s2[++top2] = num;
    }
}

void enqueue(int size)
{
    int num;
    if (top1 == size - 1)
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("Enter a number here : ");
        scanf("%d", &num);
        Push1(num, size); // O(1)
    }
}
void dequeue(int size)
{
    int a, b;
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        while(top1!=-1)
        {
            Push2(Pop1(),size);
        }
        a = Pop2();
        printf("The dequeued element is %d\n",a);
        while(top2!=-1)
        {
            Push1(Pop2(),size);
        }
        // Update front pointer
        if (top1 == -1)
            front = rear = -1; // Queue is empty
        else
            front = 0;
    }
}

void display()
{
    if (front == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        for (int i = 0; i <= top1; i++)
        {
            printf("%d ", s1[i]);
        }
        printf("\n");
    }
}

void Peek()
{
    if(front==-1 && rear==-1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("%d \n",s1[front]);
    }
}

void main()
{
    int size, choice;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    while (1)
    {
        printf("\nSelect an option to perform :\n1. Enqueue an element in the queue,\n2. Dequeue the front element from the queue\n3. Display the queue,\n4. View the front element of the queue\n5.exit\n");
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