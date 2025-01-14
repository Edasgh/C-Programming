#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

int getLength(Node *head)
{
    int length = 0;
    if (head == NULL)
        return 0;
    else
    {
        Node *t = head;
        while (t != NULL)
        {
            t = t->next;
            length++;
        }
        return length;
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
        *head = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
    }
    *tail = newNode;
}

void insAtBeg(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty...creating a node\n");
        createNode(head, tail);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d", &(newNode->data));
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insAtEnd(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty...creating a node\n");
        createNode(head, tail);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d", &(newNode->data));
        newNode->next = NULL;
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void insAtPos(Node **head, Node **tail, int pos)
{
    if (*head == NULL)
    {
        printf("The linked list is empty...creating a node\n");
        createNode(head, tail);
    }
    else
    {

        int length = getLength(*head);
        if (pos < 0 || pos > length)
        {
            printf("Invalid position!\n");
        }
        else if (pos == 0)
            insAtBeg(head, tail);
        else if (pos == length)
            insAtEnd(head, tail);
        else
        {
            int i = 0;
            Node *t = *head;
            while (i < pos - 1 && t != NULL)
            {
                i++;
                t = t->next;
            }
            // 2 3 4 5
            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter data : ");
            scanf("%d", &(newNode->data));
            newNode->next = t->next;
            newNode->prev = t;
            t->next->prev = newNode;
            t->next = newNode;
        }
    }
}

void insAfterPos(Node **head, Node **tail)
{
    int pos;
    printf("Enter the position to insert a node after that : ");
    scanf("%d", &pos);
    insAtPos(head, tail, pos + 1);
}

void insAfterValue(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty...creating a node\n");
        createNode(head, tail);
    }
    else
    {
        int value;
        printf("Enter the value to insert a node after that : ");
        scanf("%d", &value);
        if ((*head)->data == value)
            insAtBeg(head, tail);
        else if ((*tail)->data == value)
            insAtEnd(head, tail);
        else
        {
            int flag = 0;
            Node *t = *head;
            while (t != NULL)
            {
                if (t->data == value)
                {
                    Node *newNode = (Node *)malloc(sizeof(Node));
                    printf("Enter data : ");
                    scanf("%d", &(newNode->data));
                    newNode->prev = t;
                    newNode->next = t->next;
                    t->next->prev = newNode;
                    t->next = newNode;
                    return;
                }
                t = t->next;
            }

            printf("The value %d is not found!\n", value);
        }
    }
}

// prev | data | next
void insertNode(Node **head, Node **tail)
{
    printf("\n...Inserting a node...\n");
    int ch;
    printf("\nSelect an option : \n1.Insert a node at beginning position,\n2.Insert a node at end position,\n3.Insert a node at a specific position,\n4.Insert a node after a specific position,\n5.Insert a node after a specific value\nSelect : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        insAtBeg(head, tail);
        break;
    case 2:
        insAtEnd(head, tail);
        break;
    case 3:
    {
        int pos;
        printf("Enter a position to insert a node : ");
        scanf("%d", &pos);
        insAtPos(head, tail, pos);
    }
    break;
    case 4:
        insAfterPos(head, tail);
        break;
    case 5:
        insAfterVal(head, tail);
        break;
    default:
        printf("Invalid option!\n");
    }
}

void delFromBeg(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else if (*head == *tail)
    {
        Node *t = *head;
        printf("The deleted element is %d\n", t->data);
        *head = *tail = NULL;
        free(t);
    }
    else
    {
        Node *t = *head;
        printf("The deleted element is %d\n", t->data);
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(t);
    }
}

void delFromEnd(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else if (*head == *tail)
    {
        Node *t = *head;
        printf("The deleted element is %d\n", t->data);
        *head = *tail = NULL;
        free(t);
    }
    else
    {
        Node *t = *head;
        while (t->next != *tail)
        {
            t = t->next;
        }
        Node *temp = t->next;
        t->next = NULL;
        *tail = t;
        printf("The deleted element is %d\n", temp->data);
        free(temp);
    }
}

void delFromPos(Node **head, Node **tail, int pos)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        int length = getLength(*head);
        if (pos < 0 || pos > length)
        {
            printf("Invalid position!\n");
        }
        else if (pos == 0)
            delFromBeg(head, tail);
        else if (pos == length)
            delFromEnd(head, tail);
        else
        {
            // 2 3 4 5
            // 0 1 2 3
            Node *t = *head;
            int i = 0;
            while (i < pos - 1 && t != NULL)
            {
                i++;
                t = t->next;
            }

            Node *temp = t->next;
            t->next = temp->next;
            t->next->prev = t;
            printf("The deleted element is %d\n", temp->data);
            free(temp);
        }
    }
}

void delAfterPos(Node **head, Node **tail)
{
    int pos;
    printf("Enter the position to delete a node after that : ");
    scanf("%d", &pos);
    delFromPos(head, tail, pos + 1);
}

void delAtVal(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        int val;
        printf("Enter the value to delete : ");
        scanf("%d", &val);

        if ((*head)->data == val)
            delFromBeg(head, tail);
        else if ((*tail)->data == val)
            delFromEnd(head, tail);
        else
        {
            // Traverse the list to find the value
            Node *t = *head;
            while (t->next != NULL && t->next->data != val)
            {
                t = t->next;
            }

            // If the value is found
            if (t->next->data == val)
            {
                Node *temp = t->next;
                t->next = temp->next;
                printf("The deleted element is %d\n", temp->data);
                free(temp);
            }
            else
            {
                printf("The value %d is not found in the linked list!\n", val);
            }
        }
    }
}

void deleteNode(Node **head, Node **tail)
{
    printf("\n...Deleting a node...\n");
    int ch;
    printf("\nSelect an option : \n1.Delete a node from the beginning position,\n2.Delete a node from the end position,\n3.Delete a node from a specific position,\n4.Delete a node after a specific position,\n5.Delete a node at a specific value\nSelect : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        delFromBeg(head, tail);
        break;
    case 2:
        delFromEnd(head, tail);
        break;
    case 3:
    {
        int pos;
        printf("Enter a position to delete node : ");
        scanf("%d", &pos);
        delFromPos(head, tail, pos);
    }
    break;
    case 4:
        delAfterPos(head, tail);
        break;
    case 5:
        delAtVal(head, tail);
        break;
    default:
        printf("Invalid option!\n");
    }
}

void display(Node *head, Node *tail)
{
    if (head == NULL)
    {
        printf("The linked list is empty!\n");
    }
    else
    {

        printf("\nTraversing in forwards manner\n");
        Node *t = head;
        while (t != NULL)
        {
            printf("%d ", t->data);
            t = t->next;
        }
    }
}

void search(Node *head, Node *tail)
{
    if (head == NULL)
    {
        printf("The linked list is empty!\n");
    }
    else
    {
        int val;
        printf("Enter the value to search : ");
        scanf("%d", &val);
        if (head->data == val)
            printf("The value %d is found at head\n", val);
        else if (tail->data == val)
            printf("The value %d is found at tail\n", val);
        else
        {
            Node *t = head;
            int i = 0;
            while (t != NULL)
            {

                if (t->data == val)
                {
                    printf("The value %d is found at index = %d\n", val, i);
                    return;
                }
                i++;
                t = t->next;
            }

            printf("The value %d is not found!\n", val);
        }
    }
}

void reverse(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        Node *curr = *head, *temp = NULL;

        while (curr != NULL)
        {
            // Swap the prev and next pointers for the current node
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to the next node in the original list (which is prev after swap)
            curr = curr->prev;
        }

        // Adjust the head and tail pointers
        if (temp != NULL)
        {
            *head = temp->prev;
            *tail = *head;
            while ((*tail)->next != NULL)
            {
                *tail = (*tail)->next;
            }
        }

        printf("\n....Doubly linked list reversed...\n");
        display(*head, *tail);
    }
}

int main()
{
    Node *head = NULL, *tail = NULL;
    int ch;
    while (1)
    {
        printf("\nSelect an option to perform : \n1.Create a node, \n2.Delete a node , \n3.Insert a node, \n4.Display the doubly linked list,\n5.Search an element in the doubly linked list,\n6.Reverse the doubly linked list\n7.Exit \nSelect : ");
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
            search(head, tail);
            break;
        case 6:
            reverse(&head, &tail);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}
