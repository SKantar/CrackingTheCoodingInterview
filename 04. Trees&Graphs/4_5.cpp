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


bool is_bst(Node *root){
    if(!root)
        return true;

    if(root->right && root->right->data <= root->data)
        return false;
    if(root->left && root->left->data >= root->data)
        return false;
    return is_bst(root->left) && is_bst(root->right);
}


int main(){
    Node *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    populate(&root, arr, 0, n - 1);
    int height;
    printf("%s", is_bst(root) ? "Yes" : "No");
    return 0;
}
