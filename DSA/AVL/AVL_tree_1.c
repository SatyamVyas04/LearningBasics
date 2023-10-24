#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

// Max Function
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns Height of the Root
int getHeight(AVLNode *root) {
    int lh, rh;
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->height;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->height;

    if (lh > rh)
        return (lh);
    return (rh);
}

// Return a New Node
AVLNode *createNode(int data) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

// Rotate Right Function
AVLNode *rotateRight(AVLNode *node) {
    AVLNode *newnode = node->left;
    AVLNode *child = newnode->right;
    newnode->right = node;
    node->left = child;

    // Update heights
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newnode->height = max(getHeight(newnode->left), getHeight(newnode->right)) + 1;
    return newnode;
}

// Rotate Left Function
AVLNode *rotateLeft(AVLNode *node) {
    AVLNode *newnode = node->right;
    AVLNode *child = newnode->left;
    newnode->left = node;
    node->right = child;

    // Update heights
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newnode->height = max(getHeight(newnode->left), getHeight(newnode->right)) + 1;
    return newnode;
}

// Returns Balance Factor of a Node
int getBalance(AVLNode *root) {
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->height;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->height;
    return lh - rh;
}

// Inserting a Node into the AVL Tree
AVLNode *insert(AVLNode *root, int data) {
    if (root == NULL) {
        AVLNode *new_node = createNode(data);
        printf("\n> Inserted %d", data);
        root = new_node;
    } else if (data > root->data) {
        root->right = insert(root->right, data);
        if (getBalance(root) == -2) {
            printf("\n>> Balancing the Tree...");
            if (data > root->right->data) {
                printf("\n>>> RR Case...");
                root = rotateLeft(root);
            } else {
                root->right = rotateRight(root->right);
                printf("\n>>> RL Case...");
                root = rotateLeft(root);
            }
        }
    } else if (data < root->data) {
        root->left = insert(root->left, data);
        if (getBalance(root) == 2) {
            printf("\n>> Balancing the Tree...");
            if (data < root->left->data) {
                printf("\n>>> LL Case...");
                root = rotateRight(root);
            } else {
                printf("\n>>> LR Case...");
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        }
    } else {
        printf("\n>> Data Already Exists!");
        return root;
    }
    root->height = getHeight(root);
    return root;
}

// Display Level Order Traversal
void levelOrderTraversal(AVLNode *root, int level) {
    if (root == NULL) {
        printf("None ");
        return;
    }
    if (level == 0)
        printf("%d ", root->data);
    else if (level > 0) {
        levelOrderTraversal(root->left, level - 1);
        levelOrderTraversal(root->right, level - 1);
    }
}
void displayAVLTree(AVLNode *root) {
    int height = getHeight(root);
    for (int i = 0; i <= height; i++) {
        printf("\n> ");
        levelOrderTraversal(root, i);
    }
}

// Display Inorder
void display_in(AVLNode *root) {
    if (root != NULL) {
        display_in(root->left);
        printf("%d ", root->data);
        display_in(root->right);
    }
}

// Display Preorder
void display_pre(AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}

// Display Postorder
void display_post(AVLNode *root) {
    if (root != NULL) {
        display_post(root->left);
        display_post(root->right);
        printf("%d ", root->data);
    }
}

// Function to Free Memory
void freeAVLTree(AVLNode *root) {
    if (root != NULL) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root);
    }
}

// Function to Display All Traversals
void displayAll(AVLNode *root) {
    printf("In-order Traversal: ");
    display_in(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    display_pre(root);
    printf("\n");

    printf("Post-order Traversal: ");
    display_post(root);
    printf("\n");

    printf("Level-order Traversal: ");
    displayAVLTree(root);
    printf("\n");
}

int main() {
    AVLNode *root = NULL;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    printf("\n\nAVL Tree Traversals:\n");
    displayAll(root);
    freeAVLTree(root);
    return 0;
}
