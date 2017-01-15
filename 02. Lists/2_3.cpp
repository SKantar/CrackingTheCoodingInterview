/**
*   Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
*   the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
*   that node.
*
*   EXAMPLE
*   Input:the node c from the linked list a->b->c->d->e->f
*   Result: nothing is returned, but the new linked list looks like a ->b->d- >e- >f
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

/***************************************************
*  Time Complexity: O(1)
*  Memory Compleity: O(1)
***************************************************/
void deleteMiddleNode(Node *node){
    Node *del = node->next;

    node->data = node->next->data;
    node->next = node->next->next;

    free(del);
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

    deleteMiddleNode(head->next->next);

    print(head);
    return 0;
}

