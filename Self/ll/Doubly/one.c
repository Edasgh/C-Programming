//doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL, *tail = NULL;

//get the length of the doubly linked list
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

//create a node -> normal left to right flow
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


//traverse a doubly linked list
void traverse()
{
    int ch;
    printf("Select traversal mode : \n1.Forwards,\n2.Backwards\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        displayFor();
        break;
    case 2:
        displayBack();
        break;
    }
}

//reverse a doubly linked list
void reverse(){
    Node *temp, *pr, *nxt;
    temp = head;
    while(temp!=NULL)
    {
        pr = temp->prev;
        nxt = temp->next;
        temp->prev=nxt;
        temp->next = pr;
        temp = nxt;
    }
    temp = head;
    head = tail;
    tail = temp;

    //display in forwards manner
    displayFor();
}


//insertion functions
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

// insert a node in the linked list
void insertNode()
{
    int ch;
    printf("\nEnter an option\n1.Insert a node at the start,\n2.Insert a node at the end,\n3.Insert a node at a specific position\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
       insertAtStart();
        break;
    case 2:
       insertAtEnd();
        break;
    case 3:
        insertAtPos();
        break;
    default:
        printf("Invalid option\n");
    }
}

//deletion functions

void delFromStart()
{
    Node *temp;
    temp = head->next;
    temp->prev = NULL;
    free(temp);
}

void delFromEnd()
{
    Node *temp;
    temp = tail;
    (temp->prev)->next = NULL;
    tail = tail->prev;
    free(temp);
}

void delFromPos()
{
    int pos, length, i;
    length = getLength();
    printf("Enter the position from where you want to delete : ");
    scanf("%d", &pos);
    Node *temp;
    if (pos <= 0 || pos > length)
    {
        printf("Invalid position\n");
    }
    else if (pos == 1)
    {
        delFromStart();
    }
    else if (pos == length)
    {
        delFromEnd();
    }
    else
    {
        i = 1;
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
        free(temp);
    }
}

//delete a node in the linked list
void delNode()
{
    int ch;
    printf("\nEnter an option\n1.Delete a node from the start,\n2.Delete a node from the end,\n3.Delete a node from a specific position\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        delFromStart();
        break;
    case 2:
        delFromEnd();
        break;
    case 3:
        delFromPos();
        break;
    default:
        printf("Invalid option\n");
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\nPlease select an option to perform :\n1. Create a node,\n2.Traverse the linked list, \n3. Insert a node \n4.Delete a node,\n5. reverse the linked list,\n6.exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            createNode();
            break;
            case 2:
            traverse();
            break;
            case 3:
            insertNode();
            break;
            case 4:
            delNode();
            break;
            case 5:
            reverse();
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("Invalid choice!\n");
        }

    }
}