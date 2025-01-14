// gcc circularL.c -o a
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
        // 2 3 4 5
        while (t->next != head)
        {
            length++;
            t = t->next;
        }
        return length;
    }
}
void createNode(Node **head, Node **tail)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data : ");
    scanf("%d", &(newNode->data));
    newNode->prev = NULL;
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
    (*tail)->next = *head;
    (*head)->prev = *tail;
}

void insAtBeg(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("\nThe linked list is empty. Creating a node..\n");
        createNode(head, tail);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d", &(newNode->data));
        newNode->prev = *tail;
        newNode->next = *head;

        (*head)->prev = newNode;
        (*tail)->next = newNode;
        *head = newNode;
    }
}

void insAtEnd(Node **head, Node **tail)
{
    createNode(head, tail);
}

void insAtPos(Node **head, Node **tail, int pos)
{
    if (*head == NULL)
    {
        printf("\nThe linked list is empty. Creating a node..\n");
        createNode(head, tail);
    }
    else
    {
        int length = getLength(*head);
        if (pos < 0 || pos > length)
        {
            printf("Invalid position\n");
        }
        else if (pos == 0)
            insAtBeg(head, tail);
        else if (pos == length)
            insAtEnd(head, tail);
        else
        {

            Node *t = *head;
            int i = 0;
            while (i < pos - 1 && t->next->next != *head)
            {
                // 2 3 4 5 6
                i++;
                t = t->next;
            }

            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter data : ");
            scanf("%d", &(newNode->data));
            newNode->prev = t;
            newNode->next = t->next;
            t->next->prev = newNode;
            t->next = newNode;
        }
    }
}

void insAfterPos(Node **head, Node **tail)
{
    int pos;
    printf("Enter a position to insert node after that : ");
    scanf("%d", &pos);
    int length = getLength(*head);
    if (pos + 1 == length + 1)
    {
        insAtEnd(head, tail);
    }
    else
    {
        insAtPos(head, tail, pos + 1);
    }
}

void insAfterVal(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("\nThe linked list is empty. Creating a node..\n");
        createNode(head, tail);
    }
    else
    {
        int value;
        printf("Enter the value to insert a node after that : ");
        scanf("%d", &value);
        if ((*head)->data == value)
        {
            insAtPos(head, tail, 1);
        }
        else if ((*tail)->data == value)
        {
            insAtEnd(head, tail);
        }
        else
        {
            Node *t = *head;
            while (t->next != *head)
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

            printf("The value %d is not found in the linked list!\n", value);
        }
    }
}

void delFromBeg(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("\nThe linked list is empty\n");
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
        (*tail)->next = (*head)->next;
        (*head)->next->prev = *tail;
        *head = (*head)->next;
        free(t);
    }
}

void delFromEnd(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("\nThe linked list is empty\n");
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
        Node *t = *tail;
        printf("The deleted element is %d\n", t->data);
        (*tail)->prev->next = *head;
        (*head)->prev = (*tail)->prev;
        *tail = (*tail)->prev;
        free(t);
    }
}

void delFromPos(Node **head, Node **tail, int pos)
{
    if (*head == NULL)
    {
        printf("\nThe linked list is empty\n");
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
            Node *t = *head;
            int i = 0;
            while (i < pos - 1 && t->next != *head)
            {
                i++;
                t = t->next;
            }

            Node *temp = t->next;
            printf("The deleted element is %d\n", temp->data);
            // 0 1 2 3
            temp->next->prev = t;
            t->next = temp->next;
            free(temp);
        }
    }
}

void delAtVal(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("\nThe linked list is empty\n");
    }
    else
    {
        int value;
        printf("Enter the value to delete : ");
        scanf("%d", &value);

        if ((*head)->data == value)
            delFromBeg(head, tail);
        else if ((*tail)->data == value)
            delFromEnd(head, tail);
        else
        {
            Node *t = *head;
            while (t->next != *head)
            {
                if (t->data == value)
                {
                    Node *temp = t;
                    printf("The deleted element is %d\n", temp->data);
                    // 2 3 4 5
                    t->next->prev = t->prev;
                    t->prev->next = t->next;
                    free(temp);
                    return;
                }
                t = t->next;
            }

            printf("The value %d is not found in the linked list!\n", value);
        }
    }
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty!\n");
    }
    else
    {

        Node *t = head;
        while (t->next != head)
        {
            printf("%d ", t->data);
            t = t->next;
        }
    }
}

void reverse(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
        return;
    }

    Node *prev = NULL, *curr = *head, *next = NULL;
    *tail = *head; // Keep track of the original tail for reconnection

    do
    {
        // Store the next node
        next = curr->next;

        // Reverse the current node's next pointer
        curr->next = prev;

        // Move pointers one step forward
        prev = curr;
        curr = next;
    } while (curr != *head); // Stop when we loop back to the original head

    // Reconnect the last node to the new head
    (*head)->next = prev;

    // Update the head pointer
    *head = prev;

    // Update the tail pointer if required
    (*tail)->next = *head;

    printf("\nReversing the linked list\n");
}

void search(Node *head, Node *tail)
{
    if (head == NULL)
    {
        printf("The linked list is empty\n");
        return;
    }
    else
    {
        int value;
        printf("Enter the value you want to search : ");
        scanf("%d", &value);
        if (head->data == value)
        {
            printf("The value %d is found at head\n", value);
        }
        else if (tail->data == value)
        {
            printf("The value %d is found at tail\n", value);
        }
        else
        {
            Node *t = head;
            int i = 0;
            while (t->next != head)
            {
                if (t->data == value)
                {
                    printf("The value %d is found at index = %d", value, i);
                    return;
                }
                i++;
                t = t->next;
            }
            printf("The value %d is not found\n", value);
        }
    }
}

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
            display(head);
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
