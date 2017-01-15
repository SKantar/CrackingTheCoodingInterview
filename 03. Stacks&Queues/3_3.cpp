/**
*   Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
*   Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
*   threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be
*   composed of several stacks and should crea0te a new stack once the previous one exceeds capacity.
*   SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack
*   (that is, pop () should return the same values as it would if there were just a single stack).
*   FOLLOW UP
*   Implement a function popAt ( int index) which performs a pop operation on a specific sub-stack.
**/

#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
#define LIMIT 2

using namespace std;

typedef struct Stack{

    int n = 0;
    vector<stack<int> > setOfStack;

    void push(int data){
        if(++n % LIMIT == 1){
            stack <int> t;
            setOfStack.push_back(t);
        }
        setOfStack[(n - 1) / LIMIT].push(data);
    }

    int pop(){
        int t = setOfStack[(n - 1) / LIMIT].top();
        setOfStack[(n - 1) / LIMIT].pop();
        if(--n % LIMIT == 0)
            setOfStack.pop_back();
        return t;
    }

    bool empty(){
        return n == 0;
    }
}Stack;

int main(){
    Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);

    while(!S.empty())
        printf("%d ", S.pop());

}
