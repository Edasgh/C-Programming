#include <stdio.h>
#include <stdlib.h>
// singly linked list
// gcc Linkedl.c -o a
typedef struct node
{
    int data;
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
        while (t != 0)
        {
            t = t->next;
            length++;
        }

        return length;
    }
}

void createNode(Node **head, Node **tail)
{
    printf("\n...Inserting a node...\n");
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data : ");
    scanf("%d", &(newNode->data));
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

void insAtBeg(Node **head, Node **tail)
{

    if (*head == NULL)
    {
        printf("The linked list is empty, creating a node..\n");
        createNode(head, tail);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d", &(newNode->data));
        newNode->next = *head;
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
        printf("The linked list is empty, creating a node..\n");
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

            int i = 0;
            Node *t = *head;
            while (i < pos - 1 && t != NULL)
            {
                i++;
                t = t->next;
            }
            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter data : ");
            scanf("%d", &(newNode->data));
            newNode->next = t->next;
            t->next = newNode;
        }
    }
}

void insAfterPos(Node **head, Node **tail)
{
    int pos;
    printf("Enter the position to insert after that : ");
    scanf("%d", &pos);
    insAtPos(head, tail, pos + 1);
}

void insAfterVal(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty, creating a node..\n");
        createNode(head, tail);
    }
    else
    {
        int value, flag = 0;
        printf("Enter the value to insert a node after that : ");
        scanf("%d", &value);

        Node *t = *head;
        if (t->data == value)
        {
            flag = 1;
        }

        while (t->data != value && t != NULL)
        {
            t = t->next;
            if (t->data == value)
                flag = 1;
        }

        if (flag == 1)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter data : ");
            scanf("%d", &(newNode->data));
            newNode->next = t->next;
            t->next = newNode;
        }
        else
        {
            printf("The value %d is not found!\n", value);
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
        int pos;
        printf("Enter a position to insert a node : ");
        scanf("%d", &pos);
        insAtPos(head, tail, pos);
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
        // 2 3 4
        Node *t = *head;
        while (t->next != *tail)
        {
            t = t->next;
        }
        Node *temp = t->next;
        *tail = t;
        t->next = NULL;
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
            printf("Invalid position\n");
        }
        else if (pos == 0)
            delFromBeg(head, tail);
        else if (pos == length)
            delFromEnd(head, tail);
        else
        {
            // 2 3 4 5 6
            Node *t = *head;
            int i = 0;
            while (i < pos - 1 && t != NULL)
            {
                i++;
                t = t->next;
            }
            Node *temp = t->next;
            t->next = temp->next;
            printf("The deleted element is %d\n", temp->data);
            free(temp);
        }
    }
}

void delAfterPos(Node **head, Node **tail)
{
    int pos;
    printf("Enter a position to delete a node after that : ");
    scanf("%d", &pos);
    delFromPos(head, tail, pos);
}

void delAtVal(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        int value, flag = 0;
        printf("Enter the value to delete that : ");
        scanf("%d", &value);

        if ((*head)->data == value)
            delFromBeg(head, tail);
        else if ((*tail)->data == value)
            delFromEnd(head, tail);
        else
        {
            // 2 3 4 5 6
            Node *t = *head;
            int flag = 0;
            while (t->next->data != value && t != NULL)
            {
                t = t->next;
                if (t->next->data == value)
                    flag = 1;
            }

            if (flag == 1)
            {
                Node *temp = t->next;
                t->next = temp->next;
                printf("The deleted element is %d\n", temp->data);
                free(temp);
            }
            else
            {
                printf("The value %d is not found!\n", value);
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
        int pos;
        printf("Enter a position to delete node : ");
        scanf("%d", &pos);
        delFromPos(head, tail, pos);
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

void display(Node *head)
{
    if (head == NULL)
        printf("The linked list is empty\n");
    else
    {
        printf("Printing the linked list..\n");
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
        printf("The linked list is empty\n");
    }
    else
    {
        int value;
        printf("Enter a value to search : ");
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
            int flag = 0, i = 0;
            Node *t = head;
            while (t->data != value && t != NULL)
            {
                i++;
                t = t->next;
                if (t->data == value)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
            {
                printf("The value %d is found at index = %d\n", value, i);
            }
            else
            {
                printf("The value %d is not found!\n", value);
            }
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
        Node *curr = *head, *prev = NULL, *next;
        while (curr != NULL)
        {
            // Store next
            next = curr->next;

            // Reverse current node's next pointer
            curr->next = prev;

            // Move pointers one position ahead
            prev = curr;
            curr = next;
        }
        *head = prev;
        printf("\nReversing the linked list \n");
        display(prev);
    }
}

int main()
{
    Node *head = NULL, *tail = NULL;
    int ch;
    while (1)
    {
        printf("\nSelect an option to perform : \n1.Create a node,\n2.Delete a node,\n3.Insert a node,\n4.Display the linked list,\n5.Reverse the linked list,\n6.Search a value in the linked list,\n7.exit\n Select : ");
        scanf("%d", &ch);
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
            reverse(&head, &tail);
            break;
        case 6:
            search(head, tail);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
        }
    }

    return 0;
}