// gcc LinkedList.c -o a
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int getLength(Node **head)
{
    int length = 0;
    if (*head == NULL)
    {
        return 0;
    }
    else
    {
        Node *t = *head;
        while (t != NULL)
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
    printf("Enter a data to insert : ");
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
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a data to insert : ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (*head == NULL)
    {
        *tail = newNode;
    }
    else
    {
        newNode->next = *head;
    }

    *head = newNode;
}
void insAtEnd(Node **head, Node **tail)
{
    createNode(head, tail);
}
// 2 3 4 5
// 0 1 2 3
void insAtAnyPos(Node **head, Node **tail)
{
    int length = getLength(head);
    int pos;
    printf("Enter the position to insert data");
    scanf("%d", &pos);
    if (pos < 0 || pos > length - 1)
    {
        printf("Invalid position\n");
    }
    else if (pos == 0)
        insAtBeg(head, tail);
    else if (pos == length - 1)
        insAtEnd(head, tail);
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter a data to insert : ");
        scanf("%d", &(newNode->data));
        Node *t = *head;
        for (int i = 0; i < pos - 1; i++)
        {
            t = t->next;
        }
        newNode->next = t->next;
        t->next = newNode;
    }
}
// 2 3 4 5
// 0 1 2 3

void insAfterAnyPos(Node **head,Node **tail)
{
    int length = getLength(head);
    int pos;
    printf("Enter the position to insert data after that");
    scanf("%d", &pos);
    if (pos < 0 || pos > length - 1)
    {
        printf("Invalid position\n");
    }
    else
    {
      if(pos==length-1) insAtEnd(head,tail);
      else
      {
          Node *newNode = (Node *)malloc(sizeof(Node));
          printf("Enter a data to insert : ");
          scanf("%d", &(newNode->data));
          Node *t = *head;
          for (int i = 0; i < pos; i++)
          {
              t = t->next;
          }
          newNode->next = t->next;
          t->next = newNode;
      }
    }
}

void insAfterAnyValue(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linkedlist is empty, creating a node \n");
        createNode(head, tail);
    }
    else
    {
        int num;
        printf("Enter a value to insert after that : ");
        scanf("%d", &num);
        Node *t = *head;
        int flag = 0;
        // 2 3 [] 4 5   //3
        // 0 1 2 3
        if (t->data == num)
            flag = 1;

        while (t->data != num && t != NULL)
        {
            t = t->next;
            if (t->data == num)
                flag = 1;
        }
        if (flag == 1)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            printf("Enter a data to insert : ");
            scanf("%d", &(newNode->data));
            newNode->next = t->next;
            t->next = newNode;
        }
        else
        {
            printf("The value %d is not found!\n", num);
        }
    }
}

void insertNode(Node **head, Node **tail)
{
    int ch;
    printf("Select an option :\n1.Insert a node at beginning,\n2.Insert a node at end,\n3.Insert a node at any position,\n4.Insert a node after any position,\n5.Insert a node after any value\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
        insAtBeg(head,tail);
        break;
        case 2:
        insAtEnd(head,tail);
        break;
        case 3:
        insAtAnyPos(head,tail);
        break;
        case 4:
        insAfterAnyPos(head,tail);
        break;
        case 5:
        insAfterAnyValue(head,tail);
        break;
        default:
        printf("Invalid Choice\n");
    }
}

// insertatbeg, at end
// del from beg, from end at a pos, at a value
// insert after a position, after a value
// 2 3 4 5 6
void delFromBeg(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
       if(*head==*tail)
       {
          Node *t = *head;
          printf("The deleted element is %d\n", t->data);
          free(t);
          *head = *tail = NULL;
       }
       else
       {
           Node *t = *head;
           *head = (*head)->next;
           printf("The deleted element is %d\n", t->data);
           free(t);
       }
    }
}
// 2 3 4 5
void delFromEnd(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        if(*head==*tail)
        {
            printf("Deleted data %d\n",(*head)->data);
            Node *t = *head;
            free(t);
            *head = *tail = NULL;
        }
        else
        {
            Node *t = *head;
            while (t->next != *tail)
            {
                t = t->next;
            }
            Node *temp = t->next;
            printf("Deleted data %d\n", temp->data);
            t->next = NULL;
            *tail = t;
            free(temp);
        }
    }
}

void delAtAnyPos(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linkedList is empty\n");
    }
    else
    {
        int pos;
        printf("Enter the position to delete data");
        scanf("%d", &pos);
        // 2 3 4 5 6
        // 0 1 2 3 4  //3
        int length = getLength(head);
        if (pos >= 0 && pos <= length - 1)
        {
            if(pos==0) delFromBeg(head,tail);
            else if(pos==length-1) delFromEnd(head,tail);
            else
            {
                Node *t = *head;
                for (int i = 0; i < pos - 1; i++)
                {
                    t = t->next;
                }
                Node *temp = t->next;
                t->next = temp->next;
                printf("The deleted element is %d\n", temp->data);
                free(temp);
            }

        }
        else
        {
            printf("Invalid position\n");
        }
    }
}
void delAfterAnyPos(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linkedList is empty\n");
    }
    else
    {
        int pos;
        printf("Enter the position to delete data after that");
        scanf("%d", &pos);
        int length = getLength(head);
        if (pos > 0 && pos < length - 1)
        {
            // 2 3 4 5 6
            // 0 1 2 3 4          // 3
            Node *t = *head;
            for (int i = 0; i < pos; i++)
            {
                t = t->next;
            }
            Node *temp = t->next;
            t->next = temp->next;
            printf("The deleted element is %d\n", temp->data);
            free(temp);
        }
        else
        {
            printf("Invalid position\n");
        }
    }
}

void delAtAnyValue(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linkedlist is empty!\n");
    }
    else
    {
        int num;
        printf("Enter data to delete");
        scanf("%d", &num);

        // 2 3 4 5
        // 0 1 2 3
        // 4
        Node *t = *head;
        if (t->data == num)
        {
            delFromBeg(head, tail);
        }
        else if ((t->next)->data == num)
        {
            Node *temp = t->next;
            t->next = temp->next;
            printf("Deleted data : %d\n", temp->data);
            free(temp);
        }
        else if((*tail)->data==num)
        {
            delFromEnd(head,tail);
        }
        else
        {
            int flag = 0;
            while ((t->next)->data != num && t != NULL)
            {
                t = t->next;
                if (t->data == num)
                    flag = 1;
            }

            if (flag == 1)
            {
                Node *temp = t->next;
                t->next = temp->next;
                printf("Deleted data : %d\n", temp->data);
                free(temp);
            }
            else
            {
                printf("The value %d is not found!\n", num);
            }
        }
    }
}

void delAfterAnyValue(Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("The linkedlist is empty!\n");
    }
    else
    {
        int num;
        printf("Enter data to delete");
        scanf("%d", &num);

        // 2 3 4 5
        // 0 1 2 3
        // 4
        Node *t = *head;

        if (t->data == num)
        {
            Node *temp = t->next;
            t->next = temp->next;
            printf("Deleted data : %d\n", temp->data);
            free(temp);
        }
        else
        {
            int flag = 0;
            while (t->data != num && t != NULL)
            {
                t = t->next;
                if (t->data == num)
                {
                    flag = 1;
                }
            }

            if (flag == 1)
            {
                if(t->next==*tail)
                {
                    delFromEnd(head,tail);
                }
                else
                {
                    Node *temp = t->next;
                    t->next = temp->next;
                    printf("Deleted data : %d\n", temp->data);
                    free(temp);
                }
            }
            else
            {
                printf("The value %d is not found!\n", num);
            }
        }
    }
}

void deleteNode(Node **head, Node **tail)
{
    int ch;
    printf("Select an option : \n1.Delete a node from starting position,\n2.Delete a node at end,\n3.Delete a node at a value,\n4.Delete a node after a value,\n5.Delete a node from a position,\n6.Delete a node after a position\n");
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
        delAtAnyValue(head, tail);
        break;
    case 4:
        delAfterAnyValue(head, tail);
        break;
    case 5:
        delAtAnyPos(head, tail);
        break;
    case 6:
        delAfterAnyPos(head, tail);
        break;

    default:
        printf("Invalid option\n");
        break;
    }
}

void display(Node *head)
{
    // function to traverse a linked list
    if (head == NULL)
    {
        printf("The linkedlist is empty\n");
    }
    else
    {

        Node *t = head;
        while (t != NULL)
        {
            printf("%d ", t->data);
            t = t->next;
        }
    }
}

void main()
{
    Node *head = NULL, *tail = NULL;
    int ch;
    while (1)
    {
        printf("Select an option to perform :\n1.Create a node, \n2.Insert a node,\n3.Delete a node,\n4.Traverse the linked list,\n5.exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
           createNode(&head, &tail);
            break;
        case 2:
           insertNode(&head,&tail);
            break;
        case 3:
           deleteNode(&head,&tail);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid option!");
        }
    }
}