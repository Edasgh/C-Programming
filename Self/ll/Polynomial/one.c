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
        if(temp->coeff!=0)
        {
        printf(" %dx^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
        {
            printf(" +");
        }
        }
        temp = temp->next;
    }
}

void addPol(Node *head1, Node *head2, int power1, int power2)
{
    printf("\nAdding the polynomials\n");
    // addpol
    Node *t = power2 > power1 ? head2 : head1;
    Node *t1 = power2 < power1 ? head2 : head1;

    if (power1 == power2)
    {
        t = head1;
        t1 = head2;
    }

    int i = 0;
    int tp = power2 > power1 ? power2 : power1;
    if (power1 == power2)
        tp = power1;

    Node *head3 = NULL, *tail3 = NULL;
    while (i <= tp && t1 != NULL)
    {
        Node *newN = (Node *)malloc(sizeof(Node));
        newN->next = NULL;
        newN->coeff = t1->coeff + t->coeff;
        newN->power = t->power;
        if (head3 == NULL)
        {
            head3 = tail3 = newN;
        }
        else
        {
            tail3->next = newN;
            tail3 = newN;
        }
        t1 = t1->next;
        t = t->next;
        i++;
    }

    while (i <= tp && t != NULL)
    {
        Node *newN = (Node *)malloc(sizeof(Node));
        newN->next = NULL;
        newN->coeff = 0 + t->coeff;
        newN->power = t->power;
        if (head3 == NULL)
        {
            head3 = tail3 = newN;
        }
        else
        {
            tail3->next = newN;
            tail3 = newN;
        }
        t = t->next;
        i++;
    }

    Node *t2 = head3;
    printPol(t2);
}

void subPol(Node *head1, Node *head2, int power1, int power2)
{
    printf("\nSubtracting the polynomials\n");
    // Subpol
    Node *t = power2 > power1 ? head2 : head1;
    Node *t1 = power2 < power1 ? head2 : head1;

    if (power1 == power2)
    {
        t = head1;
        t1 = head2;
    }

    int i = 0;
    int tp = power2 > power1 ? power2 : power1;
    if (power1 == power2)
        tp = power1;

    Node *head3 = NULL, *tail3 = NULL;

    while (i <= tp && t1 != NULL)
    {
        Node *newN = (Node *)malloc(sizeof(Node));
        newN->next = NULL;
        newN->coeff = t->coeff - t1->coeff;
        newN->power = t->power;
        if (head3 == NULL)
        {
            head3 = tail3 = newN;
        }
        else
        {
            tail3->next = newN;
            tail3 = newN;
        }
        t1 = t1->next;
        t = t->next;
        i++;
    }
    while (i <= tp && t != NULL)
    {
        Node *newN = (Node *)malloc(sizeof(Node));
        newN->next = NULL;
        newN->coeff = t->coeff;
        newN->power = t->power;
        if (head3 == NULL)
        {
            head3 = tail3 = newN;
        }
        else
        {
            tail3->next = newN;
            tail3 = newN;
        }
        t = t->next;
        i++;
    }

    Node *t3 = head3;
    printPol(t3);
}

void multpol(Node *head1, Node *head2, int power1, int power2)
{
    printf("\nMultiplying the polynomials\n");
    Node *t = power2 > power1 ? head2 : head1;
    Node *t1 = power2 < power1 ? head2 : head1;
    if (power1 == power2)
    {
        t = head1;
        t1 = head2;
    }
    Node *head3 = NULL, *tail3 = NULL;

    Node *t2 = t1;

    // multPol
    // 5x^3 + 4x^2 + 10x^1 + 1x^0
    // 2x^2 + 3x^1 + 4x^0

    // = 10x^5 + 15x^4 + 20x^3 + 8x^4 + 12x^3 + 16x^2 + 20x^3 + 30x^2 + 40x^1 + 2x^2 + 3x^1 + 4x^0
    // = 10x^5 + 23x^4 + 52x^3 + 48x^2 + 43x^1 + 4x^0
    while (t != NULL)
    {

        t2 = t1;
        while (t2 != NULL)
        {
            Node *newN = (Node *)malloc(sizeof(Node));
            newN->next = NULL;
            newN->coeff = (t->coeff) * (t2->coeff);
            newN->power = (t->power) + (t2->power);
            if (head3 == NULL)
            {
                head3 = tail3 = newN;
            }
            else
            {
                tail3->next = newN;
                tail3 = newN;
            }
            t2 = t2->next;
        }
        t = t->next;
    }

    Node *T = head3;

    Node *a = head3;
    int p1, p2;
    while (T != NULL)
    {
        a = head3;
        while (a != NULL)
        {
            if (T->power == a->power && T->next != a->next && a->coeff != 0)
            {
                T->coeff = (T->coeff) + (a->coeff);
                a->coeff = 0;
            }
            a = a->next;
        }
        T = T->next;
    }

    T = head3;
    printPol(T);
    printf("\n");
}

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

    addPol(head1, head2, power1, power2);
    subPol(head1, head2, power1, power2);
    multpol(head1, head2, power1, power2);
}