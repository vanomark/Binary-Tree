#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef int Data_t;

struct Node_t {
    Data_t data;
    struct Node_t* left;
    struct Node_t* right;
};

Node_t*    newNode                    (Data_t data);
Node_t*    insertNode                 (Node_t* root, int data);
Node_t*    findMin                    (Node_t* root);
Node_t*    findNode                   (Node_t* root, int value);
Node_t*    deleteNodeWithoutSubtree   (Node_t* root, int data);
void       deleteNodeWithSubtree      (Node_t* root, int value);
void       deleteTree                 (Node_t* root);
int        treeDepth                  (Node_t* root);
void       inorderTraversal           (Node_t* root);
void       preorderTraversal          (Node_t* root);
void       postorderTraversal         (Node_t* root);

#define DELETE_TREE(tree) deleteTree(tree); tree = NULL;
#define INSERT_NODE()

#endif /* TREE_H */