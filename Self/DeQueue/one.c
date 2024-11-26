//implementation of deque using arrays
#include <stdio.h>
#include <stdlib.h>

int dq[100];
int front = -1, rear = -1 ;

int isEmpty()
{
    int result=0;
    if(front == -1 && rear ==-1)
    {
        result=1;
    }
    return result;

}

int isFull(int size)
{
    int result = 0;
    if((front == 0 && rear == size-1)||(front==rear+1)||((rear+1)%size==front))
    {
        result = 1;
    }
    return result;
}

void enqueuefront(int size)
{
  int empty, full , num;
  empty = isEmpty();
  full = isFull(size);
  if (full)
  {
    printf("The dequeue is full\n");
  }
  else
  {
    printf("Enter a number here : ");
    scanf("%d",&num);
    if(empty)
    {
        front = rear = 0;
        dq[front]=num;
    }
    else if(front==0)
    {
      front = size - 1;
      dq[front]=num;

    }
    else
    {
        front--;
        dq[front]=num;
    }
  }
}

void enqueuerear(int size)
{
  int empty, full, num;
  empty = isEmpty();
  full = isFull(size);
  if (full)
  {
      printf("The dequeue is full\n");
  }
  else
  {
      printf("Enter a number here : ");
      scanf("%d", &num);
      if (empty)
      {
          front = rear = 0;
          dq[rear] = num;
      }
      else if (rear == size - 1)
      {
          rear = 0;
          dq[rear] = num;
      }
      else
      {
          rear++;
          dq[rear] = num;
      }
  }
}

void dequeuefront(int size)
{
 int empty;
 empty = isEmpty();
 if(empty) printf("The dequeue is empty\n");
 else if(front==rear)
 {
   printf("The dequed element is %d\n",dq[front]);
   front = rear = -1;
 }
 else if(front == size-1)
 {
     printf("The dequed element is %d\n", dq[front]);
     front = 0;
 }
 else
 {
     printf("The dequed element is %d\n", dq[front]);
     front++;
 }
}

void dequeuerear(int size)
{
    int empty;
    empty = isEmpty();
    if (empty)
        printf("The dequeue is empty\n");
    else if (front == rear)
    {
        printf("The dequed element is %d\n", dq[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("The dequed element is %d\n", dq[rear]);
        rear = size - 1;
    }
    else
    {
        printf("The dequed element is %d\n", dq[rear]);
        rear--;
    }
}

void display(int size)
{
  int i = front;
  while(i!=rear)
  {
    printf("%d",dq[i]);
    i = (i+1) % size;

  }
  printf("%d",dq[rear]);
}

    void main()
{
    int size,choice,ch1,ch2;
    printf("Enter the dequeue size here : ");
    scanf("%d",&size);
    while(1)
    {
        printf("\nSelect an option to perform :\n1. Enqueue an element,\n2. Dequeue an element,\n3. Display the dequeue,\n4. exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Select an option:\n1. Enqueue at front,\n2.Enqueue at rear\n");
            scanf("%d",&ch1);
            if(ch1 == 1)
            {
                enqueuefront(size);
            }
            else if(ch1 == 2)
            {
                enqueuerear(size);
            }
            else
            {
                printf("Invalid option\n");
            }
            break;
            case 2:
                printf("Select an option:\n1. Dequeue at front,\n2.Dequeue at rear\n");
                scanf("%d", &ch1);
                if (ch1 == 1)
                {
                    dequeuefront(size);
                }
                else if (ch1 == 2)
                {
                    dequeuerear(size);
                }
                else
                {
                    printf("Invalid option\n");
                }
            break;
            case 3:
            display(size);
            break;
            case 4:
            exit(0);
            break;
            default:
                printf("Invalid option\n");
        }
    }

}
