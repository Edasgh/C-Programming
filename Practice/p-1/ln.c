#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createNode(struct node **newNode, struct node **head, struct node **temp)
{

    *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value : ");
    scanf("%d", &((*newNode)->data));
    (*newNode)->next = NULL;

    if (*head == NULL||*head==0)
    {
        *head = *newNode;
    }
    else
    {
        (*temp)->next = *newNode;
    }

    *temp = *newNode;
}

void traverse(struct node **head, struct node **temp)
{
    int count = 0;
    while ((*temp) != 0 || (*temp) != NULL)
    {
        *temp = (*temp)->next;
        printf(" %d ", (*temp)->data);
        count++;
    }

    printf("\nThe length of the linked list is %d", count);
}

void insert(struct node **head, struct node **temp, struct node **newNode)
{
    int op, pos;
    printf("Select an option : \n1.Insert at starting position , \n2. Insert at a specific position \n3.Insert at end of the linked list");
    scanf("%d", &op);
    // 4 5 6
    switch (op)
    {
    case 1:
        *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value : ");
        scanf("%d", &((*newNode)->data));
        (*newNode)->next = *head;
        *head = *newNode;
        break;
    case 2:
        printf("Enter the position where you want to insert : ");
        scanf("%d", &pos);
        *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value : ");
        scanf("%d", &((*newNode)->data));

        int i = 1;
        *temp = *head;
        while (i < pos)
        {
            *temp = (*temp)->next;
            i++;
        }
        (*newNode)->next = (*temp)->next;
        (*temp)->next = *newNode;

        break;
    case 3:
        *newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value : ");
        scanf("%d", &((*newNode)->data));
        *temp = *head;
        while((*temp)->next!=0||(*temp)->next!=NULL)
        {
            *temp = (*temp)->next;

        }
        (*temp)->next = *newNode;
        (*newNode)->next = NULL;
        break;
    default:
    }
}


void remove(struct node **head, struct node **temp, struct node **nextNode)
{
    int op, pos;
    printf("Select an option : \n1.Delete from the starting position , \n2. Delete from a specific position \n3.Delete from the end of the linked list");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
       *temp = *head;
       *head = (*head)->next;
       free(temp);
        break;
    
    case 2:
        printf("Enter the position from where you want to delete : ");
        scanf("%d", &pos);
        int i=1;
        *temp = *head;
        while(i<pos-1)
        {
            *temp = (*temp)->next;
            i++;
        }
        *nextNode = (*temp)->next;
         (*temp)->next = (*nextNode)->next;
         free(*nextNode);
        break;
    
    case 3:
    struct node **t;
        *temp = *head;
        while((*temp)->next!=NULL)
        {
            *t = *temp;
            *temp = (*temp)->next;
        }
        if(*temp==*head)
        {
            *head = NULL;
            free(*head);
        }
        else
        {

        (*t)->next = NULL;
        free(*temp);
        }

        break;
    
    default:
        
    }
}
void main()
{
}