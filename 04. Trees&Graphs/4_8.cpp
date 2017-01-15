/**
*   First Common Ancestor: Design an algorithm and write code to find the first common ancestor
*   of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
*   necessarily a binary search tree.
**/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


/************************************************************
*                                                           *
*                       Test                                *
*                                                           *
*************************************************************/
typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

void populate(Node **root, int *arr, int start, int end){
    if(end < start)
        return;

    int pivot = (start + end) / 2;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = arr[pivot];
    node->left = NULL;
    node->right = NULL;

    populate(&(node->left), arr, start, pivot - 1);
    populate(&(node->right), arr, pivot + 1, end);

    *root = node;
}

/************************************************************/

bool contains(Node *node, Node *n){
    if(node == NULL)
        return false;
    if(node == n)
        return true;
    return contains(node->left, n) || contains(node->right, n);
}

Node *first_common_ancestor(Node *root, Node *p, Node *q){
    if(!contains(root, p) || !contains(root, q))
        return NULL;

    bool left_p = contains(root->left, p);
    bool left_q = contains(root->left, q);

    if(left_p == left_q)
        return first_common_ancestor(left_p ? root->left : root->right, p, q);
    else
        return root;
}

int main(){
    Node *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    populate(&root, arr, 0, n - 1);


    printf("%d\n", first_common_ancestor(root, root->left->left, root->right->right)->data);


    return 0;
}
