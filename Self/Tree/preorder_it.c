// C program to traverse a binary tree in preorder style
#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform preorder traversal
void preOrder(struct Node* root, int* ans, int* index) {
    if (!root) return;

    // Using a stack to simulate recursion
    struct Node* stack[1000]; // Assuming max 1000 nodes in the tree
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct Node* temp = stack[top--];

        // Add the current node's data to the result array
        ans[(*index)++] = temp->data;

        // Push the right child first so the left child is processed first
        if (temp->right) stack[++top] = temp->right;
        if (temp->left) stack[++top] = temp->left;
    }
}

int main() {
    // Example usage
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int ans[1000]; // Assuming max 1000 nodes
    int index = 0;

    preOrder(root, ans, &index);

    // Print the result
    printf("Preorder Traversal: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
