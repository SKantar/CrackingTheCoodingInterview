/**
*   Three in One: Describe how you could use a single array to implement three stacks.
**/

#include <cstdio>
#include <cstdlib>

#define MAXN 900

using namespace std;

typedef struct Stack{
    int array[MAXN];

    int n_1 = 0;
    int n_2 = MAXN / 3;
    int n_3 = MAXN - 1;

    void push(int stack_number, int data){
        switch(stack_number){
            case 1: array[n_1++] = data; break;
            case 2: array[n_2++] = data; break;
            case 3: array[n_3--] = data; break;
        }
    }

    int pop(int stack_number){
        switch(stack_number){
            case 1: return array[--n_1];
            case 2: return array[--n_2];
            case 3: return array[++n_3];
        }
    }

    bool empty(int stack_number){
         switch(stack_number){
            case 1: return n_1 == 0;
            case 2: return n_2 == MAXN / 3;
            case 3: return n_3 == MAXN - 1;
        }
    }


}Stack;


int main(){
    Stack S;

    S.push(1, 1);
    S.push(1, 10);

    S.push(2, 2);
    S.push(2, 20);

    S.push(3, 3);
    S.push(3, 30);

    printf("%d\n", S.pop(1));
    printf("%d\n", S.pop(2));
    printf("%d\n", S.pop(3));

    return 0;
}
