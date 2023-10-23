// Create an AVLNode ADT and complete the following functions:
// 1. createNode
// 2. displayAVLTree
// 3. getHeight
// 4. rotateRight
// 5. rotateLeft
// 6. getBalance
// 7. insert
// 8. freeAVLTree

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

AVLNode *createNode(int data) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0; // Root Initialisation
}

// Function to display the AVLTree in level-order
void displayAVLTree(AVLNode *root) {
}

// Function to display the AVLTree in-order
void display_in(AVLNode *root) {
    if (root != NULL) {
        display_in(root->left);
        printf("%d ", root->data);
        display_in(root->right);
    }
}

// Function to display the AVLTree pre-order
void display_pre(AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}

// Function to display the AVLTree post-order
void display_post(AVLNode *root) {
    if (root != NULL) {
        display_post(root->left);
        display_post(root->right);
        printf("%d ", root->data);
    }
}

// Function to get Height of a AVLTree Node
int getHeight(AVLNode *node) {
    if (!node)
        return 0;
    else {
        int left_height = tree_height(node->left);
        int right_height = tree_height(node->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

// function for performing a right rotate
AVLNode *rotateRight(AVLNode *node) {
    AVLNode *newnode = node->left;
    AVLNode *child = newnode->right;
    newnode->right = node;
    node->left = child;

    // Updating Heights and Returning
    node->height = getHeight(node);
    newnode->height = getHeight(node);
    return newnode;
}

// function for performing a left rotate
AVLNode *rotateLeft(AVLNode *node) {
    AVLNode *newnode = node->right;
    AVLNode *child = newnode->left;
    newnode->left = node;
    node->right = child;

    // Updating Heights and Returning
    node->height = getHeight(node);
    newnode->height = getHeight(node);
    return newnode;
}

// get balance factor of given node
int getBalance(AVLNode *node) {
    return getHeight(node->right) - getHeight(node->left);
}

// Function to Insert a new Node in AVLTree
void insert(AVLNode **root, int data) {
}

// This frees the memory used by the AVL tree
void freeAVLTree(AVLNode *root) {
    while (1) {
        if (root == NULL) {
            break;
        } else if (root != NULL && root->left != NULL) {
            freeTree(root->left);
        } else if (root != NULL && root->right != NULL) {
            freeTree(root->right);
        } else {
            free(root);
            return;
        }
    }
}

void main() {
    // Testing all Methods
}