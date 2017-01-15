/**
*   Sum Lists: You have two numbers represented by a linked list, where each node contains a single
*   digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
*   function that adds the two numbers and returns the sum as a linked list.
*
*   EXAMPLE
*   Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
*   Output: 2 -> 1 -> 9. That is, 912.
*
*   FOLLOW UP
*   Suppose the digits are stored in forward order. Repeat the above problem.
*   Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
*   Output: 9 -> 1 -> 2. That is, 912.
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

/***************************************************
*  Example:
*  Time Complexity: O(n)
*  Memory Compleity: O(n)
****************************************************
Node *add(Node *a, Node *b){
    Node *result = NULL;
    int tmp = 0;

    while(1){
        if(!a && !b)
            break;
        if(a){
            tmp += a->data;
            a = a->next;
        }

        if(b){
            tmp += b->data;
            b = b->next;
        }

        insert(&result, tmp % 10);
        tmp /= 10;
    }

    return reverse(result);
}
***************************************************/

/***************************************************
*  Follow Up:
*  Time Complexity: O(n)
*  Memory Compleity: O(n)
***************************************************/
Node *add(Node *a, Node *b){
    Node *result = NULL;
    int tmp = 0;

    a = reverse(a);
    b = reverse(b);

    while(1){
        if(!a && !b)
            break;
        if(a){
            tmp += a->data;
            a = a->next;
        }

        if(b){
            tmp += b->data;
            b = b->next;
        }

        insert(&result, tmp % 10);
        tmp /= 10;
    }

    return result;
}

void print(Node *head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    Node *a = NULL;
    Node *b = NULL;

    insert(&a, 7);
    insert(&a, 1);
    insert(&a, 6);

    insert(&b, 5);
    insert(&b, 9);
    insert(&b, 2);

    print(add(a, b));
    return 0;
}
