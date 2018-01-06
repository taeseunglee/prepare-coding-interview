/* Given a sorted(increasing order) array with unique integer elements, write an
 * algoritm to create a binary search tree minimal height */
#include <algorithm>
#include "./binarySearchTree.h"

binarySearchTree bst;
int arr[] = {1, 2, 5, 7 , 8, 15, 123, 34, 1000, 52};

void makeMinimalTree(int startIdx, int endIdx);

int main() {
    int size = sizeof(arr) / sizeof(int);

    std::sort(arr, arr + sizeof(arr)/sizeof(int));
    printf("arr : ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    makeMinimalTree(0, size-1);
    bst.inorder();

    return 0;
}

void makeMinimalTree(int startIdx, int endIdx) {
    int midIdx = (startIdx + endIdx) / 2;
    bst.insert (arr[midIdx]);
    makeMinimalTree(startIdx, midIdx-1);
    makeMinimalTree(midIdx+1, endIdx);
}
