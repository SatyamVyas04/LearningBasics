#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function for creating a new BST node
TreeNode *createNode(int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

// Function to insert a new value into the BST
TreeNode *insert(TreeNode *root, int data) {
    if (root == NULL) {
        printf("\n> Inserted %d\n", data);
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("\n> Data Already Exists!\n");
        return root;
    }
    return root;
}

// Function to display the BST in-order
void display_in(TreeNode *root) {
    if (root != NULL) {
        display_in(root->left);
        printf("%d ", root->data);
        display_in(root->right);
    }
}

// Function to display the BST pre-order
void display_pre(TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}

// Function to display the BST post-order
void display_post(TreeNode *root) {
    if (root != NULL) {
        display_post(root->left);
        display_post(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the BST's min value node
TreeNode *minValueNode(TreeNode *root) {
    if (root->left != NULL) {
        return minValueNode(root->left);
    } else {
        return root;
    }
}

// Function to display the BST's max value node
TreeNode *maxValueNode(TreeNode *root) {
    if (root->right != NULL) {
        return maxValueNode(root->right);
    } else {
        return root;
    }
}

// Function to find a node in the BST
TreeNode *findNode(struct TreeNode *root, int data) {
    TreeNode *temp = root;
    while (temp != NULL && temp->data != data) {
        if (data < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    if (temp == NULL) {
        printf("\n> Node Not Found! Returning NULL\n");
        return NULL;
    } else {
        printf("\n> Node Found! Returning Node\n");
        return temp;
    }
}

// Function to delete a node with given value from the BST
TreeNode *delete(TreeNode *root, int data) {
    if (root == NULL)
        return NULL;
    if (root->data < data)
        root->right = delete (root->right, data);
    else if (root->data > data)
        root->left = delete (root->left, data);
    else {
        // Leaf Node
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } // One Child: Right
        else if (root->left == NULL) {
            TreeNode *right = root->right;
            free(root);
            return right;
        } // One Child: Left
        else if (root->right == NULL) {
            TreeNode *left = root->left;
            free(root);
            return left;
        } // Both Children Present
        else {
            TreeNode *right_min_node = minValueNode(root->right);
            int right_min = right_min_node->data;
            root->data = right_min;
            delete (root->right, right_min);
        }
    }
    return root;
}

// Function to display (L D R) of a Node
void nodeDetails(TreeNode *root) {
    if (root == NULL) {
        printf("\n> ---- Node ----\n");
        printf("> Left Data Right\n");
        printf("> NULL NULL  NULL\n");

    } else {
        printf("\n> ---- Node ----\n");
        printf("> Left Data Right\n");
        
        if (root->left == NULL) {
            printf("> NULL ");
        } else {
            printf("> %4d ", root->left->data);
        }

        printf("%4d", root->data);

        if (root->right == NULL) {
            printf("  NULL \n");
        } else {
            printf(" %5d \n", root->right->data);
        }
    }
}

void main() {
    TreeNode *root = createNode(5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 6);

    printf("\nTraversals\n");
    display_in(root);
    printf(" <--- InOrder Traversal\n");
    display_pre(root);
    printf(" <--- PreOrder Traversal\n");
    display_post(root);
    printf(" <--- PostOrder Traversal\n");

    TreeNode *min = minValueNode(root);
    nodeDetails(min);
    TreeNode *max = maxValueNode(root);
    nodeDetails(max);

    TreeNode *find = findNode(root, 5);
    nodeDetails(find);

    find = findNode(root, 11);
    nodeDetails(find);

    root = delete (root, 5);
    printf("\nTraversals\n");
    display_in(root);
    printf(" <--- InOrder Traversal\n");
    display_pre(root);
    printf(" <--- PreOrder Traversal\n");
    display_post(root);
    printf(" <--- PostOrder Traversal\n");
}
