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


bool is_balansed(Node *root, int *height){

    int lh = 0, rh = 0;

    if(!root)
    {
        *height = 0;
        return true;
    }
    bool left = is_balansed(root->left, &lh);
    bool right = is_balansed(root->right, &rh);

    *height = max(lh, rh) + 1;

    return left && right && abs(lh - rh) < 2;

}


int main(){
    Node *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    populate(&root, arr, 0, n - 1);
    int height;
    printf("%s", is_balansed(root, &height) ? "Yes" : "No");
    return 0;
}
