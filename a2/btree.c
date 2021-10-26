/* Name: ChayathornTeratanitnan
 * ID:6280945
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

Node* make_node(int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
}

void insert(Node **tree, int val) {
    // IMPLEMENT
    // if tree == null -> make root
    if (*tree == NULL) {
        *tree = make_node(val);
    }
    // continue left subtree
    else if (val <= (*tree)->data) {
        insert(&(*tree)->left, val);
    }
    // continue right subtree
    else {
        insert(&(*tree)->right, val);
    }
}

void print_helper(Node* tree, int depth) {
    if (tree == NULL) {
        return;
    }
    if (depth != 0) {
        for (int i = 0; i < depth-1; i++) {
            printf("  ");
        }
        printf("|-");
    }
    printf("%d\n", tree->data);
    print_helper(tree->left, depth+1);
    print_helper(tree->right, depth+1);
}

void print(Node *tree) {
    // IMPLEMENT
    print_helper(tree, 0);
}

void delete(Node *tree) {
    // IMPLEMENT
    if (tree != NULL) {
        Node* tmp = tree;
        free(tmp);
        // printf("deleted\n");
        delete(tree->left);
        delete(tree->right);
    }
}

Node *lookup(Node ** tree, int val) {
    // IMPLEMENT
    if (*tree == NULL) {
        return NULL;
    }
    else if ((*tree)->data == val) {
        return *tree;
    }
    else if (val <= (*tree)->data) {
        lookup(&(*tree)->left, val);
    }
    else if (val > (*tree)->data) {
        lookup(&(*tree)->right, val);
    }
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}
