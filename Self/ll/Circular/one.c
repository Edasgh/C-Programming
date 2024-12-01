// circular singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL, *temp;

// create node in circular l.l.
void createNode()
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a number here : ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = temp = newNode;
        head->next = head;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
        temp->next = head;
    }
    
}

// head = 150, 1|100 -> 2|250 -> 3|450 -> 5|500 -> 6|150
void display()
{
    Node *tm;
    tm = head;
    while (tm->next != head)
    {
        printf("%d ", tm->data);
        tm = tm->next;
    }
    printf("%d ", tm->data);
}

// get length
int getLength()
{
    Node *t;
    t = head;
    int length = 1;
    while (t->next != head)
    {
        length++;
        t = t->next;
    }
    return length;
}

// insert at beginning
void insertAtBeg()
{
    Node *newNode, *tm;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a number here to insert : ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;

        tm = newNode->next;
        while (tm->next != newNode->next)
        {
            tm = tm->next;
        }
        tm->next = head;
    }
}
// insert at End
void insertAtEnd()
{
    Node *newNode, *t;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a number here to insert : ");
    scanf("%d", &newNode->data);

    t = head;
    while (t->next != head)
    {
        t = t->next;
    }
    newNode->next = t->next;
    t->next = newNode;
}


void insertAtPos()
{
    int pos, length, count = 1;
    length = getLength();
    printf("Enter the position where you want to insert : ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > length)
    {
        printf("Invalid position\n");
    }
    else
    {
        Node *newNode, *t;
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter a number here to insert : ");
        scanf("%d", &newNode->data);

        if (pos == 1)
            insertAtBeg();
        else if (pos == length)
            insertAtEnd();
        else
        {
            t = head;
            while (count < pos-1)
            {
                count++;
                t = t->next;
            }
            newNode->next = t->next;
            t->next = newNode;
        }
    }
}

void insertion()
{
    int ch;
    printf("\nSelect :\n1. Insert at beginning,\n2. Insert at a specific position,\n3.Insert at end\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        insertAtBeg();
        break;
    case 2:
        insertAtPos();
        break;
    case 3:
        insertAtEnd();
        break;
    default:
        printf("Invalid option\n");
    }
}

// delete from beginning
void deleteFromBeg()
{
    Node *t, *tm;
    if (head == NULL)  printf("The linked list is empty\n");
    else
    {
        t = head;
        head = head->next;
        printf("The deleted element is %d\n", t->data);
        tm = t;
        while(tm->next!=t)
        {
            tm = tm->next;
        }
        tm->next = head;
        free(t);
    }
}

// delete from end
void deleteFromEnd()
{
    Node *t, *tm;
    int length, count = 1;
    length = getLength();
    if (head == NULL)
        printf("The linked list is empty\n");
    else
    {
        t = head;
        while (count < length-1)
        {
            count++;
            t = t->next;
        }
        tm = t->next;
        t->next = head;
        printf("The deleted element is %d\n", tm->data);
        free(tm);
    }
}

// delete from a specific position

void deleteFromPos()
{
    Node *t, *tm;
    int pos, length, count = 1;
    length = getLength();
    printf("Enter the position from where you want to delete : ");
    scanf("%d", &pos);

    if (head == NULL) printf("The linked list is empty\n");
    else
    {
        if (pos > length || pos <= 0)  printf("Invalid position\n");
        else
        {
            if (pos == 1)
                deleteFromBeg();
            else if (pos == length)
                deleteFromEnd();
            else
            {
                t = head;
                while (count < pos-1)
                {
                    count++;
                    t = t->next;
                }
                tm = t->next;
                t->next = tm->next;
                printf("The deleted element is %d\n", tm->data);
                free(tm);
            }
        }
    }
}


void deletion()
{
    int ch;
    printf("\nSelect :\n1. Delete from beginning,\n2. Delete from a specific position,\n3.Delete from end\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        deleteFromBeg();
        break;
    case 2:
        deleteFromPos();
        break;
    case 3:
        deleteFromEnd();
        break;
    default:
        printf("Invalid option\n");
    }
}


void main()
{
    int ch , length;
    while(1)
    {
        printf("\nSelect : \n1. Create a node, \n2. Display the linked list,\n3. Insert a node,\n4.Delete a node,\n5. view the length of the linked list\n6. exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            createNode();
            break;
            case 2:
            display();
            break;
            case 3:
            insertion();
            break;
            case 4:
            deletion();
            break;
            case 5:
            length = getLength();
            printf("The length of the linked list s %d\n",length);
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("Invalid option\n");
        }
    }
}