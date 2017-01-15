#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#define MAXN 500

using namespace std;

typedef struct Node{
    vector<int> adj;
}Node;

Node graph[MAXN];
bool mark[MAXN];

bool DFS(int start, int finish){
    stack<int> S;

    mark[start] = true;
    S.push(start);

    while(!S.empty()){
        int tmp = S.top();
        S.pop();

        for(int i = 0; i < graph[tmp].adj.size(); i++){
            if(!mark[graph[tmp].adj[i]]){
                if(graph[tmp].adj[i] == finish)
                    return true;
                mark[graph[tmp].adj[i]] = true;
                S.push(graph[tmp].adj[i]);
            }
        }
    }
    return false;
}


int main(){
    graph[0].adj.push_back(1);
    graph[0].adj.push_back(2);
    graph[2].adj.push_back(3);
    graph[3].adj.push_back(4);

    printf("%s", DFS(1, 4) ? "Yes" : "No");

    return 0;
}
