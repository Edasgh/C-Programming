#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void createNode(struct node **head , struct node **temp , struct node **nextNode)
{
    *nextNode = (struct node *) malloc(sizeof(struct node));
     printf("\nEnter data : ");
     scanf("%d",&((*nextNode)->data));
    
    (*nextNode)->next = 0;
    if(*head==0)
    {
        *head = *nextNode;
    }
    else
    {
        (*temp)->next = *nextNode;
    }
    *temp = *nextNode;
}

void traverseNode(struct node **head,struct node **temp)
{
    *temp =*head;
    printf("\nPrinting the linked list\n");
    while(*temp!=0)
    {
        printf(" %d ",(*temp)->data);
        *temp = (*temp)->next;
    }

}

void insertAtStart(struct node **head, struct node **temp,struct node **nextNode)
{
    *nextNode = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d", &((*nextNode)->data));
    (*nextNode)->next = *head;
    *head = *nextNode;
}
void insertAtEnd(struct node **head, struct node **temp, struct node **nextNode)
{
    *temp = *head;
    while((*temp)->next!=0)
    {
        *temp = (*temp)->next;
    }
    *nextNode = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d",&((*nextNode)->data));
    //9|0 (500)
    (*nextNode)->next =0;
   (*temp)->next = *nextNode;


}
//[100] 5|wewe 6|rtrt 7|yuyu 8|opop
//      100    200    300     400
void insertPos(struct node **head, struct node **temp,struct node **nextNode)
{
    int pos;
    printf("\nEnter the position where you want to insert : ");
    scanf("%d",&pos);

    *temp = *head;
    struct node **t;
    int i=0;
    while(i<pos-1)
    {//delete
        *t = *temp;
        *temp = (*temp)->next;
        i++;
    }

    // *nextNode = (struct node*) malloc(sizeof(struct node));
    // (*nextNode)->next = (*temp)->next;
    // (*temp)->next = *nextNode;
    (*t)->next=0;
    free(*temp);


}


void main()
{
    struct node *head , *nextNode , *temp;
    head = 0;
    int op;
    while(1)
    {
    printf("\nSelect an option :  \n1. Create a Linked List , \n2. Print a Linked List\n 3. Exit \nSelect : ");
    scanf("%d",&op);

    switch(op)
    {
        case 1:
        createNode(&head,&temp,&nextNode);
        break;
        case 2:
        traverseNode(&head,&temp);
        break;
        case 3:
        exit(0);
        break;
        default:
        printf("\nInvalid Option.\n");
    }
    }


}