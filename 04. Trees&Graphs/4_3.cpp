#include <cstdio>
#include <cstdlib>
#define MAXN 100
using namespace std;


/************************************************************
*                                                           *
*                       Test                                *
*                                                           *
*************************************************************/
typedef struct tNode{
    int data;
    struct tNode *left, *right;
}tNode;

void populate(tNode **root, int *arr, int start, int end){
    if(end < start)
        return;

    int pivot = (start + end) / 2;
    tNode *node = (tNode *)malloc(sizeof(tNode));
    node->data = arr[pivot];
    node->left = NULL;
    node->right = NULL;

    populate(&(node->left), arr, start, pivot - 1);
    populate(&(node->right), arr, pivot + 1, end);

    *root = node;
}

/************************************************************/

typedef struct lNode{
    int data;
    struct lNode *next;
}lNode;


lNode *heads[MAXN];

void add(lNode **head, int data){
    lNode *node = (lNode*)malloc(sizeof(lNode));
    node->data = data;
    node->next = *head;
    *head = node;
}

void toList(tNode *root, int depth){
    if(!root)
        return;
    toList(root->left, depth + 1);
    toList(root->right, depth + 1);
    add(heads + depth, root->data);

}

void print(lNode *head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main(){
    tNode *root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    populate(&root, arr, 0, n - 1);
    toList(root, 0);
    print(heads[0]);
    print(heads[1]);
    print(heads[2]);

    return 0;
}

