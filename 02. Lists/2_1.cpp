/**
*   Remove Dups: Write code to remove duplicates from an unsorted linked list.
*   FOLLOW UP
*   How would you solve this problem if a temporary buffer is not allowed?
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
*  Time Complexity: O(n ^ 2)
*  Memory Compleity: O(1)
****************************************************

Iterative:

void remove_dup(Node *head){
    Node *prev, *next;
    while(head){
        prev = head;
        next = head->next;
        while(next){
            if(next->data == head->data){
                prev->next = next->next;
                free(next);
            }
            else
                prev = next;
            next = prev->next;
        }

        head = head->next;
    }
}

Recursion:

void remove_dup(Node *head){
    if(!head)
        return;

    Node *prev = head;
    Node *next = head->next;

    while(next){
        if(next->data == head->data){
            prev->next = next->next;
            free(next);
        }
        else
            prev = next;
        next = prev->next;
    }

    remove_dup(head->next);
}


***************************************************/

/***************************************************
*  Time Complexity: O(n)
*  Memory Compleity: O(n)
***************************************************/
void remove_dup(Node *head){
    bool mark[MAXN];
    memset(mark, false, MAXN * sizeof(bool));

    Node *prev = head;

    while(head){
        if(mark[head->data]){
            prev->next = head->next;
            free(head);
        }
        else{
            mark[head->data] = true;
            prev = head;
        }

        head = prev->next;
    }

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

    remove_dup(head);

    print(head);
    return 0;
}
