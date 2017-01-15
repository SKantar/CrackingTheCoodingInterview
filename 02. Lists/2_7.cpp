/**
*   Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the inter­
*   secting node. Note that the intersection is defined based on reference, not value. That is, if the kth
*   node of the first linked list is the exact same node (by reference) as the jth node of the second
*   linked list, then they are intersecting.
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000

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

Node *intersecting(Node *l1, Node *l2){
    Node *tmp;
    while(l1){
        tmp = l2;
        while(tmp){
            if(l1 == tmp)
                return l1;
            tmp = tmp->next;
        }
        l1 = l1->next;
    }
    return NULL;
}
***************************************************/

/***************************************************
*  Time Complexity: O(n)
*  Memory Compleity: O(1)
***************************************************/
Node *intersecting(Node *l1, Node *l2){
    int l1_n = length(l1);
    int l2_n = length(l2);

    while(l1_n > l2_n){
        l1 = l1->next;
        l1_n --;
    }

    while(l2_n > l1_n){
        l2 = l2->next;
        l2_n--;
    }

    while(l2 != l1){
        l2 = l2->next;
        l1 = l1->next;
    }

    return l2;
}


void print(Node *head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    Node *l1 = NULL, *l2 = NULL;
    insert(&l1, 8);
    insert(&l1, 7);
    insert(&l1, 6);

    insert(&l2, 5);

    l2->next = l1;

    insert(&l2, 4);
    insert(&l2, 3);

    insert(&l1, 2);
    insert(&l1, 1);

    print(l1);
    print(l2);

    printf("%d\n",intersecting(l1, l2)->data);
    return 0;
}
