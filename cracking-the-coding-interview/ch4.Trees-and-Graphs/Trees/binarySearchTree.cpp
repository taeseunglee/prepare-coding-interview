#include <cstdio>
#include "./binarySearchTree.h"

binarySearchTree::binarySearchTree() {
    root = NULL;
    height = 0;
}
binarySearchTree::~binarySearchTree() { destroyTree(); }

void binarySearchTree::insert(int key) {
    node *newNode = new node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    node *curNode = root;
    while (curNode) {
        if (key < curNode->key) {
            if (!curNode->left) {
                curNode->left = newNode;
                return ;
            }
            curNode = curNode->left;
        }
        else if (key > curNode->key) {
            if (!curNode->right) {
                curNode->right = newNode;
                return ;
            }
            curNode = curNode->right;
        }
        else { return ; } // not insert node
    }
    root = newNode;
}

node *binarySearchTree::search(int key) {
    node *curNode = root;
    while (curNode) {
        if(key==curNode->key)
            return curNode;
        if(key<curNode->key)
            curNode = curNode->left;
        else
            curNode = curNode->right;
    }
    return NULL;
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
    printf("\nheight = %d\n", height);
}

void binarySearchTree::inorderRecur(node *root) {
    static int depth = 0;
    if (root) {
        ++ depth;
        inorderRecur(root->left);
        printf("%d ", root->key);
        inorderRecur(root->right);
        
        if (depth > height)
            height = depth;
        -- depth;
    }
}
