#include <stdio.h>

// Function to construct inorder traversal
void buildInorder(int preorder[], int postorder[], int preStart, int postStart, int postEnd, int n)
{
    if (preStart >= n || postStart > postEnd)
        return;

    // Root is the first element in preorder
    int root = preorder[preStart];

    // If there is only one node left, print it
    if (postStart == postEnd)
    {
        printf("%d ", root);
        return;
    }

    // Find the left subtree root in postorder
    int leftSubtreeRoot = preorder[preStart + 1]; // The next element in preorder
    int leftSubtreeIndex;
    for (leftSubtreeIndex = postStart; leftSubtreeIndex <= postEnd; leftSubtreeIndex++)
    {
        if (postorder[leftSubtreeIndex] == leftSubtreeRoot)
            break;
    }

    // Recursively construct the left subtree
    buildInorder(preorder, postorder, preStart + 1, postStart, leftSubtreeIndex, n);

    // Print the root
    printf("%d ", root);

    // Recursively construct the right subtree
    buildInorder(preorder, postorder, preStart + (leftSubtreeIndex - postStart) + 2, leftSubtreeIndex + 1, postEnd - 1, n);
}

void printInorder(int preorder[], int postorder[], int n)
{
    buildInorder(preorder, postorder, 0, 0, n - 1, n);
}

int main()
{
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    printf("Inorder traversal: ");
    printInorder(preorder, postorder, n);

    return 0;
}
