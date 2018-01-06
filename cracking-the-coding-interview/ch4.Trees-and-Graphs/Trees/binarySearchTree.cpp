#include <cstdio.h>
#include "./binarySearchTree.h"

binarySearchTree::binarySearchTree() { root = NULL; }
binarySearchTree::~binarySearchTree() { destroyTree(); }

void binarySearchTree::insert(int key) {
    node *newNode = new node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    node *cur_node = root;
    while (cur_node) {
        if (key < cur_node->key) {
            if (!cur_node->left) {
                cur_node->left = newNode;
                return ;
            }
            cur_node = cur_node->left;
        }
        else if (key > cur_node->key) {
            if (!cur_node->right) {
                cur_node->right = newNode;
                return ;
            }
            cur_node = cur_node->right;
        }
        else { return ; } // not insert node
    }
}

node *binarySearchTree::search(int key) {
    if(root!=NULL)
    {
        if(key==root->key)
            return root;
        if(key<root->key)
            return search(key, root->left);
        else
            return search(key, root->right);
    }
    else return NULL;
}

void binarySearchTree::destroyTree()
{
    destroyTree(root);
}

void binarySearchTree::destroyTree(node *root) {
    if (root) {
        destroyTree(root->left);
        delete root;
        destroyTree(root->right);
    }
}

void binarySearchTree::inorder() {
    printf("binarySearchTree order: ");
    inorderRecur(root);
    printf("\n");
}

void binarySearchTree::inorderRecur(node *root) {
    if (root) {
        inorderRecur(root->left);
        printf("%d ", root->key);
        inorderRecur(root->right);
    }
}
