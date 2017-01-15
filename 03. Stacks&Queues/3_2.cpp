/**
*   Stack Min: How would you design a stack which, in addition to push and pop, has a function min
*   which returns the minimum element? Push, pop and min should all operate in 0(1) time.
**/

#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct Node{
    int data;
    int min;
}Node;

typedef struct Stack{

    stack<Node> S;

    void push(int data){
        Node tmp;
        tmp.data = data;
        tmp.min = data;

        if(!S.empty())
            if(S.top().min < data)
                tmp.min = S.top().min;
        S.push(tmp);
    }

    int pop(){
        int tmp = S.top().data;
        S.pop();
        return tmp;
    }

    int min(){
        return S.top().min;
    }
}Stack;

int main(){
    Stack S;
    S.push(5);
    S.push(6);
    S.push(2);
    S.push(8);

    printf("%d\n", S.min());
    S.pop();
    S.pop();
    printf("%d\n", S.min());

    return 0;
}
