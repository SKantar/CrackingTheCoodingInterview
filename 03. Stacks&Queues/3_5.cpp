/**
*   Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
*   an additional temporary stack, but you may not copy the elements into any other data structure
*   (such as an array). The stack supports the following operations: push, pop, peek, and is Empty.
**/

#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct Stack{
    stack<int> S;

    void push(int data){
        S.push(data);
    }

    int pop(){
        int t = S.top();
        S.pop();
        return t;
    }

    bool empty(){
        return S.empty();
    }

    void sort(){
        stack<int> tmp;
        while(!S.empty()){
            tmp.push(S.top());
            S.pop();
        }

        while(!tmp.empty()){
            int t = tmp.top();
            tmp.pop();

            while(!S.empty() && S.top() < t){
                tmp.push(S.top());
                S.pop();
            }
            S.push(t);
        }
    }

}Stack;

int main(){
    Stack S;

    S.push(1);
    S.push(3);
    S.push(2);
    S.push(5);
    S.push(4);

    S.sort();

    while(!S.empty())
        printf("%d ", S.pop());

    return 0;
}
