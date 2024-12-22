// gcc polAddSub.c -o a
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int power;
    struct node *next;
} Node;

// create a polynomial
void createPol(Node **head, Node **tail,int p)
{
    if (p <= 0)
    {
        printf("\nInvalid order\n");
    }
    else
    {
        for (int i = 0; i <= p; i++)
        {
            Node *newNode;
            newNode = (Node *)malloc(sizeof(Node));
            printf("Enter the co-efficient of %d : ", i);
            scanf("%d", &(newNode->data));
            newNode->power = i;
            newNode->next = NULL;
            if (*head == NULL)
            {
                *head = newNode;
            }
            else
            {
                (*tail)->next = newNode;
            }
            *tail = newNode;
        }
    }
}

//printPol
void printPol(Node *head)
{
    Node *t;
    if(head==NULL)
    {
        printf("\nThe Polynomial doesn't exist\n");
    }
    else
    {
        printf("\n");
        t = head;
        while(t!=NULL)
        {
            printf("%d^%d ",t->data,t->power);
            if(t->next!=NULL)
            {
                printf("+");
            }

            t = t->next;
        }
        printf("\n");
    }
}

// add 2 polynomials
void addPol(Node **head1, Node **head2, int power1, int power2)
{
    if(*head1!=NULL && *head2!=NULL)
    {
        printf("\nAdding the polynomials\n");
    Node *head3 = NULL, *tail3 = NULL;
    int p = power2 > power1 ? power2 : power1;
    if (power1 == power2)
        p = power1;
    Node *t1, *t2;
    t1 = *head1;
    t2 = *head2;
    for (int i = 0; i <= p; i++)
    {
        Node *newNode;
        newNode = (Node *)malloc(sizeof(Node));
        newNode->power = i;
        newNode->next = NULL;
        int data1 = t1 == NULL ? 0 : t1->data;
        int data2 = t2 == NULL ? 0 : t2->data;
        newNode->data = data1 + data2;
        if (head3 == NULL)
        {
            head3 = newNode;
        }
        else
        {
            tail3->next = newNode;
        }

        tail3 = newNode;

        if (t1 != NULL)
            t1 = t1->next;

        if (t2 != NULL)
            t2 = t2->next;
    }

    printPol(head3);
    }else if(*head1==NULL)
    {
        printf("Printing the polynomial");
        printPol(*head2);

    }
    else if(*head2==NULL)
    {
        printf("Printing the polynomial");
        printPol(*head1);

    }
    else
    {
        printf("Can't add the polynomials");
    }
}


// subtract 2 polynomials
void subPol(Node **head1, Node **head2,int power1, int power2)
{
    if(*head1!=NULL && *head2!=NULL)
    {
    printf("\nSubtracting the polynomials\n");
    Node *head3 = NULL, *tail3 = NULL;
    int p = power2 > power1 ? power2 : power1;
    if (power1 == power2)
        p = power1;
    Node *t1, *t2;
    t1 = *head1;
    t2 = *head2;
    for (int i = 0; i <= p; i++)
    {
        Node *newNode;
        newNode = (Node *)malloc(sizeof(Node));
        int data1 = t1 == NULL ? 0 : (t1->data);
        int data2 = t2 == NULL ? 0 : (t2->data);
        newNode->data = data1 - data2;
        newNode->power = i;
        newNode->next = NULL;
        if (head3 == NULL)
            head3 = newNode;
        else
            tail3->next = newNode;

        tail3 = newNode;
        if (t1 != NULL)
            t1 = t1->next;

        if (t2 != NULL)
            t2 = t2->next;
   }

   printPol(head3);
    }
    else if (*head1 == NULL)
    {
        printf("Printing the polynomial");
        printPol(*head2);
    }
    else if (*head2 == NULL)
    {
        printf("Printing the polynomial");
        printPol(*head1);
    }
    else
    {
        printf("Can't subtract the polynomials");
    }
   
}

void main()
{
    int power1, power2;
    printf("\nEnter the highest order of the first polynomial : ");
    scanf("%d",&power1);
    Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
    createPol(&head1,&tail1,power1);
    printPol(head1);
    printf("\nEnter the highest order of the second polynomial : ");
    scanf("%d", &power2);
    createPol(&head2,&tail2,power2);
    printPol(head2);
    addPol(&head1,&head2,power1,power2);
    subPol(&head1,&head2,power1,power2);
}