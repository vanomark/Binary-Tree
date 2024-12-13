#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#ifdef AKINATOR_DEBUG
    #define ON_DEBUG(code) code 
#else
    #define ON_DEBUG(code)
#endif /* AKINATOR_DEBUG */

#include "Tree.h"
#include "TreeDump.h"

int main()
{   
    Node_t* tree = newNode(50);
    insertNode(tree, 30);    
    insertNode(tree, 10);
    insertNode(tree, 70);
    insertNode(tree, 65);
    insertNode(tree, 80);
    insertNode(tree, 66);
    insertNode(tree, 5);
    insertNode(tree, 15);
    
    preorderTraversal(tree);

    TreeDump(tree, "Graf.dot", "Graf.svg");

    DELETE_TREE(tree);

    printf("Bobic\n");

    return 0;
}

