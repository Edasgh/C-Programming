// C Program to implement a stack using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *link;
} Node;
Node *top = 0;

void Push()
{
    int num;
    printf("Enter a number to insert : ");
    scanf("%d",&num);
    Node *newNode;
    newNode = (Node *) malloc(sizeof(Node));
    newNode->data = num;
    newNode->link=top;
    top = newNode;
    
}

void Pop()
{
    if(top==0)
    {
        printf("Underflow condition\n");
    }
    else
    {
        Node *temp;
        temp = top;
        top = top->link;
        printf("The popped element is %d\n",temp->data);
        free(temp);
    }
    
}

void Peek()
{
if(top==0)
{
    printf("The stack is empty\n");
}
else
{
 printf("The topmost element is : %d\n",top->data);
}
    
}

void display()
{
    if (top == 0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        Node *temp;
        temp = top;
        while(temp!=0)
        {
            printf(" %d ",temp->data);
            temp = temp->link;
        }
    }
}

void main()
{
    int choice;

    while (1)
    {
        printf("\nPlease select an option to perform : \n 1.Push an element into the stack,\n2.Delete the topmost element from the stack,\n3.View the topmost element of the stack,\n4.Traverse the stack,\n5.Exit\n");
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
            display();

            break;
        case 5:
            exit(0);

            break;

        default:
            printf("Invalid choice!\n");
        }
    }
}
