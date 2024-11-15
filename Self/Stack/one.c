// C Program to implement a stack using array
#include <stdio.h>
#include <stdlib.h>
#define N 5

int Stack[N];
int top = -1;

void Push()
{
    int x;
    printf("Enter a number to insert : ");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        top++;
        Stack[top] = x;
    }

}

void Pop()
{
    if(top==-1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        printf("The popped item is %d\n",Stack[top]);
        top--;
    }
}

void Peek()
{
   
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The topmost item is %d\n",Stack[top]);
    }
}

void display()
{
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
    int i;
    for(i=top;i>=0;i--)
    {
        printf(" %d ",Stack[i]);
    }
    }
}

void main()
{
int choice;

while(1)
{
    printf("\nPlease select an option to perform : \n 1.Push an element into the stack,\n2.Delete the topmost element from the stack,\n3.View the topmost element of the stack,\n4.Traverse the stack,\n5.Exit\n");
    scanf("%d",&choice);

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
