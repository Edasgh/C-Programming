// gcc stackL.c -o a
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL, *tail = NULL;

void Push()
{
    int n;
    printf("\nEnter a number to insert:");
    scanf("%d", &n);
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }

    tail = newNode;
}

int Pop()
{
    Node *temp;
    if (head == NULL)
    {
        printf("\nThe stack is empty\n");
        return -1;
    }
    else
    {
        temp = head;
        while ((temp->next)->next != NULL)
        {
            temp = temp->next;
        }
        // 2 3 4 5
        tail = temp;
        temp = temp->next;
        printf("\nThe popped element is %d\n", temp->data);
        int num = temp->data;
        free(temp);
        return num;
    }
}

void Traverse()
{
    Node *t;
    if (head == NULL)
    {
        printf("\nThe stack is empty\n");
    }
    else
    {
        printf("\nTraversing the stack\n");
        t = head;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t = t->next;
        }
        // 2 3 4 5 6
        printf("\n");

    }
}


int Peek()
{
   
    if (head == NULL)
    {
        printf("\nThe stack is empty\n");
    }
    else
    {
      printf("The front element is : %d",tail->data);
      int num = tail->data;
      printf("\n");
      return num;
       
    }
}

void main()
{
    int choice;
    printf("\nStack Using Linked List\n");
    while(1)
    {
    printf("Select an option to perform :\n1.Insert an element in the stack,\n2.Delete the front element of the stack,\n3.View the topmost element of the stack,\n4.Traverse the stack,\n5.Exit\nSelect :");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
        Push();
        break;
        case 2:
        Pop();
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