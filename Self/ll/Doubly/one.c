#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL, *tail = NULL;

int getLength()
{
    int length = 0;
    Node *temp;
    if (head != NULL)
    {
        temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    else
    {
        return 0;
    }
  

   
}

void createNode()
{
    Node *newNode;
    newNode = (Node *) malloc(sizeof(Node));
    printf("Enter a number here : ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
}

void displayFor() //function to traverse the nodes in forwards manner doubly l.l.
{
    Node *temp;
    printf("Traversing in forwards manner\n");
    if(head==NULL)
    {
        printf("The head is empty");
    }
    else
    {
        temp = head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
void displayBack() //function to traverse the nodes in backwards manner doubly l.l.
{
    Node *temp;
    printf("Traversing in backwards manner\n");
    if(tail==NULL)
    {
        printf("The head is empty");
    }
    else
    {
        temp = tail;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->prev;
        }
    }
}



void insertAtStart()
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a number here : ");
    scanf("%d",&newNode->data);
    newNode->prev=NULL;
    if(head!=NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    else
    {
        newNode->next=NULL;
    }
    head = newNode;
}

void insertAtEnd()
{
    Node *newNode;
    newNode = (Node *) malloc(sizeof(Node));
    printf("Enter a number here : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertAtPos()
{
    int pos,length,i=1;
    Node *temp, *newNode;
    length = getLength();
    printf("%d\n",length);
    printf("Enter the position where you want to insert : ");
    scanf("%d",&pos);
    if(pos<=0||pos>length)
    {
      printf("Invalid position\n");
    }
    else if(pos==1)
    {
        insertAtStart();
    }
    else if(pos==length+1)
    {
        insertAtEnd();

    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode = (Node *) malloc(sizeof(Node));
        newNode->next = temp->next;
        newNode->prev = temp;
        printf("Enter a number : ");
        scanf("%d",&newNode->data);
        temp->next = newNode;
        (newNode->next)->prev = newNode;
        
    }


}

//deletion functions



void main()
{
    int choice,ch;
    while(1)
    {
        printf("\nPlease select an option to perform :\n1. Create a node,\n2.Traverse the linked list, \n3. Insert a node at beginning,\n4. Insert a node at end,\n5.Insert a node at a specific position,\n6.exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            createNode();
            break;
            case 2:
            printf("Select traversal mode : \n1.Forwards,\n2.Backwards\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                displayFor();
                break;
                case 2:
                displayBack();
                break;
            }
            break;
            case 3:
            insertAtStart();
            break;
            case 4:
            insertAtEnd();
            break;
            case 5:
            insertAtPos();
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("Invalid choice!\n");
        }

    }
}