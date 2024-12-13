#include "Tree.h"

// function for creation a new node
Node_t* newNode(Data_t data) 
{
    Node_t* node = (Node_t*) calloc (sizeof(Node_t), 1);
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

// function for deletion a tree
void deleteTree(Node_t* root) 
{
    if (root == NULL) {
        return;
    }
    
    deleteTree(root->left);
    deleteTree(root->right);

    free(root); root = NULL;
}

// function for determination tree depth
int treeDepth(Node_t* root) 
{
    if (root == NULL) {
        return 0;
    }
    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// function for a symmetrical traversal (in-order)
void inorderTraversal(Node_t* node) {
    if (node == NULL) {
        return;
    }
    printf("(");
    printf("%d", node->data);

    if (node->left ) inorderTraversal(node->left);
    printf("%d", node->data);
    if (node->right) inorderTraversal(node->right);

    printf(")");
}

// function for a straight traversal (pre-order)
void preorderTraversal(Node_t* node) 
{
    if (node == NULL) {
        return;
    }
    printf("(");
    printf("%d", node->data);

    if (node->left ) preorderTraversal(node->left);
    if (node->right) preorderTraversal(node->right);

    printf(")");
}

// Function for a reversed traversal (post-order)
void postorderTraversal(Node_t* node) 
{
    if (node == NULL) {
        return;
    }
    printf("(");

    if (node->left ) postorderTraversal(node->left);
    if (node->right) postorderTraversal(node->right);

    printf("%d", node->data);
    printf(")");
}

// function for node insertion in binary tree
// returns tree with new node
Node_t* insertNode(Node_t* root, int data) 
{
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function for search node with minimal tree element 
Node_t* findMin(Node_t* root) 
{
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node_t* findNode(Node_t* root, int value) 
{
    if (root == NULL) {
        return NULL;
    }

    if (root->data == value) {
        return root;
    }

    if (value < root->data) {
        return findNode(root->left, value);
    } else {
        return findNode(root->right, value);
    }
}

Node_t* deleteNodeWithoutSubtree(Node_t* root, int data) 
{
    if (root == NULL) {
        return root;
    }
    
    if (data < root->data) {
        root->left = deleteNodeWithoutSubtree(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNodeWithoutSubtree(root->right, data);
    } else { 
        // Deleting current node without deleting it's subtree
        if (root->left == NULL) {
            Node_t* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node_t* temp = root->left;
            free(root);
            return temp;
        } else {
            // If node has both left and right subtree, seek for min element in the right one
            Node_t* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNodeWithoutSubtree(root->right, temp->data);
        }
    }
    return root;
}

// Function for deletion node with it's subtree
void deleteNodeWithSubtree(Node_t* root, int value) 
{
    if (root == NULL) {
        return;
    }

    if (root->data == value) {
        if (root->left != NULL) {
            deleteNodeWithSubtree(root->left, root->left->data);
        }
        if (root->right != NULL) {
            deleteNodeWithSubtree(root->right, root->right->data);
        }
        free(root);

        return;
    }

    if (value < root->data) {
        deleteNodeWithSubtree(root->left, value);
    } else {
        deleteNodeWithSubtree(root->right, value);
    }
}
