/**
*   Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
*   before all nodes greater than or equal to x. If x is contained within the list the values of x only need
*   to be after the elements less than x (see below). The partition element x can appear anywhere in the
*   "right partition"; it does not need to appear between the left and right partitions.
*   EXAMPLE
*   Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
*   Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
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
*  Time Complexity: O(n)
*  Memory Compleity: O(1)
***************************************************/
void partition(Node **head, int k){
    Node *tmp = *head, *next;
    Node *head_lt = NULL, *tmp_lt = NULL;
    Node *head_ge = NULL, *tmp_ge = NULL;

    while(tmp){

        next = tmp->next;

        if(tmp->data < k)
        {

            if(!head_lt)
            {
                head_lt = tmp;
                tmp_lt = tmp;
            }
            else
            {
                tmp_lt->next = tmp;
                tmp_lt = tmp;
            }
        }
        else
        {
            if(!head_ge)
            {
                head_ge = tmp;
                tmp_ge = tmp;
            }
            else
            {
                tmp_ge->next = tmp;
                tmp_ge = tmp;
            }
        }

        tmp = next;
    }

    tmp_ge->next = NULL;

    if(!tmp_lt)
        *head = head_ge;
    else{
        tmp_lt->next = head_ge;
        *head = head_lt;

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
    insert(&head, 2);
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 5);
    insert(&head, 3);

    partition(&head, 5);

    print(head);
    return 0;
}
