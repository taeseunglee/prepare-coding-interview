#include <cstdio>
struct node {
    int key;
    node *left;
    node *right;
};

class binarySearchTree {
    public:
        binarySearchTree();
        ~binarySearchTree();

        void insert(int key);
        node *search(int key);
        void destroyTree();
        void inorder();
    private:
        node *root;
        void inorderRecur(node *root);
        void destroyTree(node *root);
        node *search(int key, node *root);
};
