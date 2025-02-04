#include <stdio.h>
#include <stdlib.h>
// gcc insertL.c -o a

typedef struct node{
    int data;
    struct node *next;
} Node;


void createNode(Node **head, Node **tail)
{
    Node *new = (Node *) malloc(sizeof(Node));
    printf("Enter data : ");
    scanf("%d",&(new->data));
    new->next = NULL;

    if(*head==NULL)
    {
        *head = new;
    }
    else
    {
        (*tail)->next = new;
    }

    *tail = new;


}

void insAtEnd(Node **head, Node **tail)
{
    createNode(head,tail);
}

void Traverse(Node *head)
{
    if(head==NULL)
    {
        printf("\nThe linked list is empty\n");
        return;
    }

    printf("\nPrinting the linked list : \n");
    Node *t = head;

    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}


void main(){
    int ch;
    Node *head = NULL , *tail = NULL;
    while(1)
    {
        printf("\nSelect :\n1. Insert a data at end in the linked list, \n2. Traverse the linked list, \n3. exit \n Select : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insAtEnd(&head,&tail);
            break;
            case 2:
            Traverse(head);
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Invalid option\n");
        }
    }
}