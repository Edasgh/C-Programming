// doubly circular linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL, *tail = NULL;

// create a node
void createNode()
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a number here : ");
    scanf("%d", &newNode->data);

    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
        head->prev = head;
        tail->next = tail;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        head->prev = tail;
        tail->next = head;
    }
}

// get the linked list's length
int getLength()
{
    int length = 1;
    Node *t;
    t = head;
    while (t->next != head)
    {
        length++;
        t = t->next;
    }

    return length;
}

// display the linked list
void displayForwards()
{
    Node *t;
    t = head;
    if (head == NULL && tail == NULL)
        printf("The linked list is empty\n");
    else
    {

        while (t->next != head)
        {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("%d ", t->data);
    }
}

void displayBackwards()
{
    Node *t;
    t = tail;
    if (head == NULL && tail == NULL)
        printf("The linked list is empty\n");
    else
    {

        while (t->prev != tail)
        {
            printf("%d ", t->data);
            t = t->prev;
        }
        printf("%d ", t->data);
    }
}

void display()
{
    int ch;
    printf("\n Select : \n1.Display in forwards manner, \n2. Display in backwards manner\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        displayForwards();
        break;
    case 2:
        displayBackwards();
        break;
    default:
        printf("Invalid choice\n");
    }
}

// head = 150, 300|1|200 -> 150|2|300 -> 200|3|150 // 300|5|150 , 250|1|200
// insert a node
// insert at beginning
void insertAtBeg()
{
    Node *newNode;

    if (head == NULL && tail == NULL)
        createNode();
    else
    {

        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter a number to insert : ");
        scanf("%d ", &newNode->data);

        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// insert at end
// head = 150, 300|1|200 -> 150|2|300 -> 200|3|150 , tail = 300 //  200|3|350 ->  300|5|150 ,tail = 350
void insertAtEnd()
{
    Node *newNode, *t;

    if (head == NULL && tail == NULL)
        createNode();
    else
    {

        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter a number to insert : ");
        scanf("%d ", &newNode->data);

        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// insert at a position
//  head = 150, 300|1|200 -> 150|2|300 -> 200|3|150 , tail = 300
void insertAtPos()
{
    int pos, length, count = 1;
    length = getLength();
    printf("Enter the position where you want to insert : ");
    scanf("%d ", &pos);
    Node *t, *newNode;
    if (head == NULL && tail == NULL)
        createNode();
    else if (pos <= length || pos > 0)
    {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter a number to insert : ");
        scanf("%d ", &newNode->data);
        
        if(pos==1) insertAtBeg();
        else if(pos==length) insertAtEnd();
        else{
            t = head;
            while(count<pos-1)
            {
                count++;
                t = t->next;
            }
            newNode->next = t;
            newNode->prev = t->prev;
            t->prev = newNode;
            newNode->prev->next = newNode;
        }

        
    }
    else
    {
        printf("Invalid position\n");
    }
}

void insertion()
{
    int ch;
    printf("\n Select : \n1.Insert at Beginning, \n2. Insert at a specific position, \n3.Insert at end \n");
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
        printf("Invalid choice\n");
    }
}

// deletion
// delete from beginning
// head = 150, 300|1|200 -> 150|2|300 -> 200|3|150 , tail = 300
void delFromBeg()
{
    Node *t;

    if (head == NULL && tail == NULL)
        printf("The linked list is empty\n");
    else if (head==tail)
    {
          t = head;
          head = tail = NULL;
          free(t);
    }
    else
    {
        t = head;
        t->next->prev = tail;
        tail->next = head->next;
        printf("The deleted element is %d\n", t->data);
        head = head->next;
        free(t);
    }
}

// delete from end
//  head = 150, 300|1|200 -> 150|2|300 -> 200|3|150 , tail = 300
void delFromEnd()
{
    Node *t;

    if (head == NULL && tail == NULL)
        printf("The linked list is empty\n");
    else if (head == tail)
    {
        t = head;
        head = tail = NULL;
        free(t);
    }
    else
    {
        t = tail;
        t->prev->next = head;
        head->prev = t->prev;
        printf("The deleted element is %d\n", t->data);
        tail = tail->prev;
        free(t);
    }
}

// delete from pos
//   head = 150, 400|1|200 -> 150|2|300 -> 200|3|400 -> 300|8|150 , tail = 400
void delFromPos()
{
    Node *t, *tm;
    int pos, count = 1, length;
    length = getLength();
    printf("Enter the position where you want to insert : ");
    scanf("%d ", &pos);
    if (head == NULL && tail == NULL)
        printf("The linked list is empty\n");
    else if (head == tail)
    {
        t = head;
        head = tail = NULL;
        free(t);
    }
    else if (pos <= length || pos > 0)
    {
        if (pos == 1)
            delFromBeg();
        else if (pos == length)
            delFromEnd();
        else
        {
            t = head;
            while (count < pos - 1)
            {
                count++;
                t = t->next;
            }
            tm = t;
            printf("The deleted element is %d\n", tm->data);
            t->prev->next = t->next;
            t->next->prev = t->prev;
            free(tm);
        }
    }
}

void deletion()
{
    int ch;
    printf("\n Select : \n1.Delete from Beginning, \n2. Delete from a specific position, \n3.Delete from end \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        delFromBeg();
        break;
    case 2:
        delFromPos();
        break;
    case 3:
        delFromEnd();
        break;
    default:
        printf("Invalid choice\n");
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("\nSelect : \n1. Create a node, \n2. Display the linked list, \n3. Insert a node, \n4. Delete a node,\n 5. View the length of the node\n6.exit\n");
        scanf("%d", &ch);
        switch (ch)
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
        printf("The length of the linked list is %d",getLength());
        break;
        case 6:
        exit(0);
        break;
        default:
        printf("Invalid choice!\n");
        }
    }
}