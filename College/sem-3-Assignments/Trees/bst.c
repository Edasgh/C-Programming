#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *create(int num)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = num;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node *getMinNode(Node *n1, Node *n2)
{
    if (n1 == NULL)
        return n2;
    if (n2 == NULL)
        return n1;
    return n1->data < n2->data ? n1 : n2;
}
Node *getMaxNode(Node *n1, Node *n2)
{
    if (n1 == NULL)
        return n2;
    if (n2 == NULL)
        return n1;
    return n1->data > n2->data ? n1 : n2;
}

void createBST(int a[], int n, Node **root)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (*root == NULL)
        {
            Node *new = create(a[i]);
            *root = new;
            continue;
        }
        else
        {
            Node *t = *root;
            while (1)
            {
                if (a[i] > t->data)
                {
                    if (t->right != NULL)
                        t = t->right;
                    else
                    {
                        t->right = create(a[i]);
                        break;
                    }
                }
                else if (a[i] <= t->data)
                {
                    if (t->left != NULL)
                        t = t->left;
                    else
                    {
                        t->left = create(a[i]);
                        break;
                    }
                }
            }
        }
    }
}

void insertInBST(int n, Node **curr)
{
    if (*curr == NULL)
    {
        printf("The BST is empty\n");
        return;
    }

    Node *t = *curr;
    while (1)
    {
        if (n > t->data)
        {
            if (t->right != NULL)
            {
                t = t->right;
            }
            else
            {
                t->right = create(n);
                break;
            }
        }
        else if (n <= t->data)
        {
            if (t->left != NULL)
            {
                t = t->left;
            }
            else
            {
                t->left = create(n);
                break;
            }
        }
    }
}

void searchInBST(int n, Node **root)
{
    if (*root == NULL)
    {
        printf("The BST is empty\n");
        return;
    }

    Node *t = *root;
    while (t != NULL)
    {
        if (n > t->data)
        {
            if (t->right != NULL)
                t = t->right;
            else
            {
                printf("%d is not found\n", n);
                break;
            }
        }
        else if (n < t->data)
        {
            if (t->left != NULL)
                t = t->left;
            else
            {
                printf("%d is not found\n", n);
                break;
            }
        }
        else if (n == t->data)
        {
            printf("%d is found in the BST\n", n);
            break;
        }
    }
}

void delFromBST(int n, Node **root)
{
    Node *curr = *root, *parent = NULL;

    while (curr != NULL && curr->data != n)
    {
        parent = curr;
        curr = (n < curr->data) ? curr->left : curr->right;
    }

    if (curr == NULL)
    {
        printf("%d is not found in the BST\n", n);
        return;
    }

    // Case 1: No child
    if (curr->left == NULL && curr->right == NULL)
    {
        if (parent == NULL)
            *root = NULL;
        else if (parent->left == curr)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(curr);
    }
    // Case 2: One child
    else if (curr->left == NULL || curr->right == NULL)
    {
        Node *child = (curr->left) ? curr->left : curr->right;
        if (parent == NULL)
            *root = child;
        else if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;
        free(curr);
    }
    // Case 3: Two children
    else
    {
        Node *sParent = curr;
        Node *successor = curr->right;
        while (successor->left != NULL)
        {
            sParent = successor;
            successor = successor->left;
        }

        curr->data = successor->data;

        if (sParent->left == successor)
            sParent->left = successor->right;
        else
            sParent->right = successor->right;

        free(successor);
    }
}

void inorderIterative(Node *root)
{
    if (root == NULL)
    {
        printf("The BST is empty\n");
        return;
    }
    else
    {
        Node *t = root;
        Node *stack[100];
        int top = -1;
        while (t != NULL || top != -1)
        {
            while (t != NULL)
            {
                stack[++top] = t;
                t = t->left;
            }

            t = stack[top--];
            printf("%d ", t->data);

            t = t->right;
        }
    }
}

void preorderIterative(Node *root)
{
    if (root == NULL)
    {
        printf("The BST is empty\n");
        return;
    }

    Node *t = root;
    Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        t = stack[top--];
        printf("%d ", t->data);

        if (t->right != NULL)
        {
            stack[++top] = t->right;
        }

        if (t->left != NULL)
        {
            stack[++top] = t->left;
        }
    }
}

void postorderIterative(Node *root)
{
    if (root == NULL)
    {
        printf("The BST is empty\n");
        return;
    }

    Node *t = root;
    Node *stack[100];
    int top = -1;
    do
    {
        while (t != NULL)
        {
            if (t->right != NULL)
            {
                stack[++top] = t->right;
            }

            stack[++top] = t;
            t = t->left;
        }

        t = stack[top--];
        if (t->right != NULL && t->right == stack[top])
        {
            stack[top--];
            stack[++top] = t;
            t = t->right;
        }
        else
        {
            printf("%d ", t->data);
            t = NULL;
        }
    } while (top != -1);
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        printf("The BST is empty\n");
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *t = queue[front++];
        printf("%d ", t->data);

        if (t->left != NULL)
            queue[rear++] = t->left;
        if (t->right != NULL)
            queue[rear++] = t->right;
    }
}

void mirrorImg(Node *root)
{
    if (root == NULL)
        return;

    Node *queue[100]; // Queue for BFS
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *curr = queue[front++];

        // Swap left and right children
        Node *temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        // Add children to queue if they exist
        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
}

void countNodes(Node *root)
{
    if (root == NULL)
        return;

    Node *t = root;
    Node *stack[100];
    int top = -1;
    int nonLeafNodes = 0, leafNodes = 0;
    stack[++top] = root;
    while (top >= 0)
    {
        t = stack[top--];
        if (t->left != NULL || t->right != NULL)
            nonLeafNodes++;

        if (t->left == NULL && t->right == NULL)
            leafNodes++;

        if (t->left != NULL)
        {
            stack[++top] = t->left;
        }

        if (t->right != NULL)
        {
            stack[++top] = t->right;
        }
    }
    printf("\nThe total no. of leaf nodes is %d & the total no. of non leaf nodes is %d\n", leafNodes, nonLeafNodes);
}

void inorderRecursive(Node *root)
{
    if (root == NULL)
        return;

    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

void preorderRecursive(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void postOrderRecursive(Node *root)
{
    if (root == NULL)
        return;

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    printf("%d ", root->data);
}

void inorder(Node *root)
{
    int ch;
    printf("\nSelect : \n 1. Inorder Iterative traversal, \n2. Inorder Recursive Traversal \n Select : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

    {
        printf("\nInorder Iterative Traversal\n");
        inorderIterative(root);
        break;
    }
    case 2:

    {
        printf("\nInorder Recursive Traversal\n");
        inorderRecursive(root);
        break;
    }

    default:
        printf("Invalid option!\n");
        break;
    }
}
void preorder(Node *root)
{
    int ch;
    printf("\nSelect : \n 1. Preorder Iterative traversal, \n2. Preorder Recursive Traversal \n Select : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

    {
        printf("\nPreorder Iterative Traversal\n");
        preorderIterative(root);
        break;
    }
    case 2:

    {
        printf("\nPreorder Recursive Traversal\n");
        preorderRecursive(root);
        break;
    }

    default:
        printf("Invalid option!\n");
        break;
    }
}
void postorder(Node *root)
{
    int ch;
    printf("\nSelect : \n 1. Postorder Iterative traversal, \n2. Postorder Recursive Traversal \n Select : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

    {
        printf("\nPostorder Iterative Traversal\n");
        postorderIterative(root);
        break;
    }
    case 2:

    {
        printf("\nPostorder Recursive Traversal\n");
        postOrderRecursive(root);
        break;
    }

    default:
        printf("Invalid option!\n");
        break;
    }
}

void getHeightOfBST(Node *root)
{
    if(root==NULL)
    {
        printf("The BST is empty\n");
        return;
    }

    Node *queue[100];
    int front = 0 ,rear = 0;
    int height=0;
    queue[rear++] = root;
    queue[rear++] = NULL;

    while(front<rear)
    {
        Node *t = queue[front++];
        if(t==NULL){
            height++;
            if(front<rear)
                queue[rear++] = NULL;
        }else{
            if(t->left!=NULL) queue[rear++] = t->left;

            if(t->right!=NULL) queue[rear++] = t->right;
        }



    }

    printf("\nHeight of the BST is %d\n",height);




}

void main()
{
    int n;
    printf("Enter the no. of inputs : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the input at index %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("\nCreating the BST\n");
    Node *root = NULL;
    createBST(a, n, &root);
    printf("\nPrinting the BST\n");
    inorder(root);
    int ch;
    while (1)
    {
        printf("\nSelect an option to perform : \n1.Insert into BST, \n2. Delete a value from BST, \n3. Search a value in  BST,\n4.preorder traversal, \n5. postorder traversal, \n6. inorder traversal,\n7. level order traversal, \n8. Mirror Image of BST, \n9. Count the leaves and non-leaves,\n10. Print the height of the BST, \n11. exit, \nSelect : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int num;
            printf("Enter the value to insert : ");
            scanf("%d", &num);
            insertInBST(num, &root);
            printf("\nThe inorder traversal\n");
            inorder(root);
            break;
        }
        case 2:
        {
            int num;
            printf("Enter the value to delete from BST : ");
            scanf("%d", &num);
            delFromBST(num, &root);
            printf("\nThe inorder traversal\n");
            inorder(root);
            break;
        }
        case 3:
        {
            int num;
            printf("Enter the value to search : ");
            scanf("%d", &num);
            searchInBST(num, &root);
            break;
        }
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            inorder(root);
            break;
        case 7:
            levelOrder(root);
            break;
        case 8:
        {
            mirrorImg(root);
            printf("Mirror Image (Inorder) : \n");
            inorder(root);
            break;
        }
        case 9:
            countNodes(root);
            break;
        case 10:
            getHeightOfBST(root);
            break;
        case 11:
            exit(0);
            break;

        default:
            printf("Invalid option!\n");
            break;
        }
    }
}