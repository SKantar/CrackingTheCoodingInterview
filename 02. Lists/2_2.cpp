/**
*   Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;


void insert(Node **head, int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = *head;

    *head = node;
}

int length(Node *head){
    int n = 0;
    while(head){
        n++;
        head = head->next;
    }
    return n;
}

/***************************************************
*  Time Complexity: O(n ^ 2)
*  Memory Compleity: O(1)
****************************************************
Node *kth_to_last(Node *head , int k, int tmp){
    if(k == tmp)
        return head;

    return kth_to_last(head->next, k, tmp - 1);

}
***************************************************/

/***************************************************
*  Time Complexity: O(n)
*  Memory Compleity: O(1)
***************************************************/

Node *kth_to_last(Node *head , int k, int n){

    while(n != k){
        head = head->next;
        n--;
    }

    return head;
}


void print(Node *head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }

}

int main(){
    Node *head = NULL;

    insert(&head, 1);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 3);

    int n = length(head);

    printf("%d\n", kth_to_last(head, 3, n)->data);

    print(head);
    return 0;
}
