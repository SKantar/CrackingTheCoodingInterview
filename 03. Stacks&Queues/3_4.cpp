/**
*   Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.
**/

#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct Queue{
    stack<int> input;
    stack<int> output;

    void push(int data){
        input.push(data);
    }

    void move(){
        if(!output.empty())
            return;

        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }

    int pop(){
        move();
        int tmp = output.top();
        output.pop();
        return tmp;
    }
}Queue;

int main(){
    Queue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);

    printf("%d\n", Q.pop());
    printf("%d\n", Q.pop());
    printf("%d\n", Q.pop());

    return 0;
}
