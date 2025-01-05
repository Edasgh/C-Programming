#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

int getLength(Node **head)
{
    // 2 3 4 5 6
    int l = 0;
    if (*head == NULL)
        return 0;
    else
    {
        Node *t = *head;
        while (t != NULL)
        {
            l++;
            t = t->next;
        }

        return l;
    }
}

void createNode(Node **head, Node **tail)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data : ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    newNode->prev = NULL;
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

void insAtBeg(Node **head, Node **tail)
{
    // 2 3 4 5
    if (*head == NULL)
    {
        createNode(head, tail);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d", &(newNode->data));

        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insAtEnd(Node **head, Node **tail)
{
    createNode(head, tail);
}

void insAtPos(Node **head, Node **tail, int posn)
{
    int length = getLength(head);
    int pos;

    // If posn is -1, read position from the user
    if (posn != -1)
    {
        pos = posn;
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);
    }

    // Check for invalid position
    if (pos < 0 || pos > length)
    {
        printf("Invalid position\n");
    }
    else if (pos == 0)
    {
        insAtBeg(head, tail);
    }
    else if (pos == length)
    {
        insAtEnd(head, tail);
    }
    else
    {

        // Handle insert in the middle
        if (*head == NULL)
        {
            printf("The linked list is empty. Creating a node..\n");
            createNode(head, tail);
        }
        else
        {
            Node *t = *head;
            int i = 0;

            // Traverse to the node just before the target position
            while (i < pos - 1 && t != NULL)
            {
                t = t->next;
                i++;
            }

            if (t == NULL)
            {
                printf("Error: Invalid traversal\n");
                return;
            }

            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter data: ");
            scanf("%d", &(newNode->data));

            // Insert the new node into the list
            newNode->next = t->next;
            newNode->prev = t;
            if (t->next != NULL)
            {
                t->next->prev = newNode;
            }
            t->next = newNode;

            // Update tail if inserted at the end
            if (newNode->next == NULL)
            {
                *tail = newNode;
            }
        }
    }
}

void insAfterPos(Node **head, Node **tail)
{
    int posn;
    printf("Enter the position to insert a node after that: ");
    scanf("%d", &posn);

    // Validate position range
    int length = getLength(head);
    if (posn < 0 || posn >= length)
    {
        printf("Invalid position\n");
        return;
    }

    // Call `insAtPos` with position incremented by 1
    insAtPos(head, tail, posn + 1);
}

void insAfterVal(Node **head, Node **tail)
{
    if (*head == NULL)
        createNode(head, tail);
    else
    {
        int val;
        printf("Enter the value : ");
        scanf("%d", &val);

        Node *t = *head;
        if (t->data == val)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter data : ");
            scanf("%d", &(newNode->data));
            newNode->next = t->next;
            if (t->next != NULL)
                t->next->prev = newNode;
            t->next = newNode;
        }
        else
        {
            while (t->data != val && t != NULL)
            {
                t = t->next;
            }
            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter data : ");
            scanf("%d", &(newNode->data));
            newNode->next = t->next;
            if (t->next != NULL)
                t->next->prev = newNode;
            t->next = newNode;
        }
    }
}

void insertNode(Node **head, Node **tail)
{
    int ch;
    printf("Select an option :\n1.Insert at beginning,\n2.Insert at end,\n3.Insert at a position,\n4.Insert after a position,\n5.Insert after a value\n");
    switch (ch)
    {
    case 1:
        insAtBeg(head, tail);
        break;
    case 2:
        insAtEnd(head, tail);
        break;
    case 3:
        insAtPos(head, tail, -1);
        break;
    case 4:
        insAfterPos(head, tail);
        break;
    case 5:
        insAfterVal(head, tail);
        break;
    default:
        printf("Invalid position!\n");
    }
}

void delFromBeg(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        if (*head == *tail)
        {
            Node *t = *head;
            *head = *tail = NULL;
            printf("The deleted element is %d\n", t->data);
            free(t);
        }
        else
        {

            Node *t = *head;
            if (t->next != NULL)
            {
                t->next->prev = NULL;
                *head = t->next;
            }
            printf("The deleted element is %d\n", t->data);
            free(t);
        }
    }
}

void delFromEnd(Node **head, Node **tail)
{
    if (*head == NULL)
        printf("The linked list is empty\n");
    else
    {
        if (*head == *tail)
        {
            Node *t = *head;
            *head = *tail = NULL;
            printf("The deleted element is %d\n", t->data);
            free(t);
        }
        else
        {
            Node *t = *head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            Node *temp = t->next;
            t->next = NULL;
            printf("The deleted element is %d\n", temp->data);
            free(temp);
        }
    }
}

void delAtPos(Node **head, Node **tail,int posn)
{
    int length = getLength(head);
    int pos;
    if(posn!=-1) pos=posn;
    else
    {
        printf("Enter the position to delete : ");
        scanf("%d",&pos);
    }

    if(pos<0||pos>length)
    {
        printf("Invalid position\n");
    }
    else
    {
        if(*head==NULL) printf("The linked list is empty\n");
        else if(*head==*tail) delFromEnd(head,tail);
        else
        {
            if(pos==0) delFromBeg(head,tail);
            else if(pos==length) delFromEnd(head,tail);
            else
            {
                int i=0;
                Node *t = *head;
                while(i<pos-1 && t!=NULL)
                {
                   t=t->next;
                   i++;
                }
                 
                if(t->next!=NULL)
                {
                  // 0 1 2 3 4
                Node *temp = t->next;
                t->next = temp->next;
                temp->next->prev = t;
                printf("The deleted element is %d\n", temp->data);
                free(temp);
                }
            }
        }
    }

}

void delAfterPos(Node **head, Node **tail)
{
    int pos;
    printf("Enter the position to delete after that : ");
    scanf("%d",&pos);
    delAtPos(head,tail,pos+1);
}

void delAtVal(Node **head, Node **tail)
{
    // 0 1 2 3
    if (*head == NULL)
        printf("The linked list is empty\n");
    else
    {
        
    }
}

void delAfterVal(Node **head, Node **tail)
{
}

void deleteNode(Node **head, Node **tail)
{
    int ch;
    printf("Select an option:\n1.Delete from starting position,\n2.Delete from end,\n3.Delete from a position,\n4.Delete after a position,\n5.Delete by a value,\n6.Delete the node after a value\n");
    switch (ch)
    {
    case 1:
        delFromBeg(head, tail);
        break;
    case 2:
        delFromEnd(head, tail);
        break;
    case 3:
        delAtPos(head, tail,-1);
        break;
    case 4:
        delAfterPos(head, tail);
        break;
    case 5:
        delAtVal(head, tail);
        break;
    case 6:
        delAfterVal(head, tail);
        break;
    default:
        printf("Invalid position!\n");
    }
}

void display(Node *head, Node *tail)
{
    if (head == NULL)
        printf("The linkedlist is empty\n");
    else
    {
        int c;
        printf("Select : \n1.Traverse from head, \n2.Traverse from tail \n");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("\nTraversing the linked list from head\n");
            Node *t = head;
            while (t != NULL)
            {
                printf("%d ", t->data);
                t = t->next;
            }
        }
        else if (c == 2)
        {
            printf("\nTraversing the linked list from tail\n");
            Node *t = tail;
            while (t != NULL)
            {
                printf("%d", t->data);
                t = t->prev;
            }
        }
        else
        {
            printf("Invalid option\n");
        }
    }
}

int main()
{
    Node *head = NULL, *tail = NULL;
    int ch;
    while (1)
    {
        printf("Select an option to perform:\n1.Create a node,\n2.Delete a node,\n3.Insert a node,\n4.Traverse the linked list\n5.Exit\n");
        switch (ch)
        {
        case 1:
            createNode(&head, &tail);
            break;
        case 2:
            deleteNode(&head, &tail);
            break;
        case 3:
            insertNode(&head, &tail);
            break;
        case 4:
            display(head, tail);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
        }
    }
}