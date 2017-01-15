/**
*   Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
*   beginning of the loop.
*   DEFINITION
*   Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
*   as to make a loop in the linked list.
*   EXAMPLE
*   Input:
*        A -> B -> C -> D -> E -> C [the same C as earlier]
*   Output:
*        C
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000

typedef struct Node{
    char data;
    struct Node *next;
}Node;


void insert(Node **head, char data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = *head;

    *head = node;
}

void print(Node *head){
    while(head){
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

bool is_circular(Node *head){
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    while(fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if(slow_ptr == fast_ptr)
            return true;
    }

    return false;

}

/***************************************************
*  Time Complexity: O(n)
*  Memory Compleity: O(1)
***************************************************/
Node *circle(Node *head){
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    while(fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if(slow_ptr == fast_ptr){
            slow_ptr = head;
            while(slow_ptr != fast_ptr){
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            return slow_ptr;
        }
    }
    return NULL;
}


int main(){
    Node *head = NULL;
    insert(&head, 'E');
    Node *e = head;
    insert(&head, 'D');
    insert(&head, 'C');
    e->next = head;
    insert(&head, 'B');
    insert(&head, 'A');

    printf("%c\n",  circle(head)->data);
    return 0;
}
