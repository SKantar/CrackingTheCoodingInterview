/**
*   Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
*   binary search tree. You may assume that each node has a link to its parent.
**/

#include <cstdio>
#include <cstdlib>
using namespace std;


/************************************************************
*                                                           *
*                       Test                                *
*                                                           *
*************************************************************/
typedef struct Node{
    int data;
    struct Node *left, *right;
    struct Node *parent;
}Node;

void populate(Node **root, int *arr, int start, int end, Node *parent){
    if(end < start)
        return;

    int pivot = (start + end) / 2;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = arr[pivot];
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    populate(&(node->left), arr, start, pivot - 1, node);
    populate(&(node->right), arr, pivot + 1, end, node);

    *root = node;
}

/************************************************************/

Node *min(Node *node){
    if(node == NULL)
        return NULL;
    while(node->left){
        node = node->left;
    }
    return node;
}

Node *successor(Node *node){
    if(node->right)
        return min(node->right);

    if(node->parent->left == node)
        return node->parent;

    return NULL;
}

int main(){
    Node *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    populate(&root, arr, 0, n - 1, NULL);

    //print(root);
    Node *node = successor(root->right->left);
    printf("%d\n", node ? node->data : -1);

    return 0;
}

