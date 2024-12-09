// gcc one.c -o a
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int power;
    struct node *next;
} Node;

Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;

void createPol(int p, Node **head, Node **tail)
{
    for (int i = 0; i <= p; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->power = i;
        printf("\nEnter the coefficient of x^%d : ", i);
        scanf("%d", &newNode->coeff);
        newNode->next = NULL;
        if (*head == NULL)
        {
            *head = *tail = newNode;
        }
        else
        {
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

void printPol(Node *head)
{
    Node *temp = head;

    printf("\n");
    while (temp != NULL)
    {
        printf(" %dx^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
        {
            printf(" +");
        }
        temp = temp->next;
    }
}

// void addPol(Node *head1, Node *head2,int power1,int power2)
// {
//     printf("\nAdding the polynomials\n");
//     // addpol
//     Node *t = power2 > power1 ? head2 : head1;
//     Node *t1 = power2 < power1 ? head2 : head1;

//     while (t1 != NULL)
//     {
//         t->coeff = t1->coeff + t->coeff;
//         t1 = t1->next;
//         t = t->next;
//     }

//     Node *t2 = power2 > power1 ? head2 : head1;
//     printPol(t2);
// }

// void subPol(Node *head1, Node *head2,int power1, int power2)
// {
//     printf("\nSubtracting the polynomials\n");
//     // Subpol
//     Node *t = power2 > power1 ? head2 : head1;
//     Node *t1 = power2 < power1 ? head2 : head1;

//     while (t1 != NULL)
//     {
//         t->coeff = t1->coeff - t->coeff;
//         t1 = t1->next;
//         t = t->next;
//     }

//     Node *t2 = power2 > power1 ? head2 : head1;
//     printPol(t2);
// }

void main()
{
    int power1, power2;
    printf("Enter the highest power of the 1st polynomial : ");
    scanf("%d", &power1);
    createPol(power1, &head1, &tail1);
    printPol(head1);
    printf("\nEnter the highest power of the 2nd polynomial : ");
    scanf("%d", &power2);
    createPol(power2, &head2, &tail2);
    printPol(head2);

    printf("\nAdding the polynomials\n");
    // addpol
    Node *t = power2 > power1 ? head2 : head1;
    Node *t1 = power2 < power1 ? head2 : head1;
    if(power1==power2){
        t = head1;
        t1 = head2;
    }

    while (t1 != NULL)
    {
        t->coeff = t1->coeff + t->coeff;
        t1 = t1->next;
        t = t->next;
    }

    Node *t2 = power2 > power1 ? head2 : head1;
    if (power1 == power2)
    {
        t2 = head1;
    }
    printPol(t2);

    printf("\nSubtracting the polynomials\n");
    // Subpol
    Node *t3 = power2 > power1 ? head2 : head1;
    Node *t4 = power2 < power1 ? head2 : head1;
    if (power1 == power2)
    {
        t3 = head1;
        t4 = head2;
    }

    while (t4 != NULL)
    {
        t3->coeff = t4->coeff - t3->coeff;
        t4 = t4->next;
        t3 = t3->next;
    }

    Node *t5 = power2 > power1 ? head2 : head1;
    if (power1 == power2)
    {
        t5 = head1;
    }
    printPol(t5);
}