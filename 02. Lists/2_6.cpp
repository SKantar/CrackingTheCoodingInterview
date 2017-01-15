/**
*   Palindrome: Implement a function to check if a linked list is a palindrome.
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

Node *reverse(Node *head){
    Node *prev = NULL;
    Node *next;

    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

Node *middle(Node *head){
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    while(fast_ptr && fast_ptr->next){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    return slow_ptr;
}



void print(Node *head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/***************************************************
*  Problem: Brokend linked list after
*  Time Complexity: O(n)
*  Memory Compleity: O(1)
***************************************************/
bool is_palindrome(Node *head){
    Node *mid = middle(head);
    Node *end = reverse(mid);

    while(head && end){
        if(head->data != end->data)
            return false;

        head = head->next;
        end = end->next;
    }
    return true;
}

int main(){
    Node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);

    printf("%s\n",is_palindrome(head) ? "Yes" : "No");

    return 0;
}


