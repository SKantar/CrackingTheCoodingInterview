#include <cstdio>
#include <cstdlib>

using namespace std;

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

void print(Node *root){
    if(!root)
        return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

int main(){
    Node *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    populate(&root, arr, 0, n - 1);

    print(root);

    return 0;
}
