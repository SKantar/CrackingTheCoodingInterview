#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

#define MAXN 256

using namespace std;

typedef struct Node{
    vector<char> adj;
}Node;

int n;
Node graph[MAXN];
int indegree[MAXN];
bool mark[MAXN];

void topo_sort(){
    queue<char> Q;
    vector<char> R;
    for(int i = 0; i < n; i++)
        if(indegree['a' + i] == 0)
            Q.push('a' + i);

    while(!Q.empty()){
        char tmp = Q.front();
        Q.pop();

        mark[tmp] = true;
        R.push_back(tmp);
        for(int i = 0; i < graph[tmp].adj.size(); i++){
            if(!mark[graph[tmp].adj[i]]){
                if(!--indegree[graph[tmp].adj[i]])
                    Q.push(graph[tmp].adj[i]);
            }
        }
    }

    if (R.size() == n)
        for(int i = 0; i < n; i++)
            printf("%c ", R[i]);
    else
        printf("ERROR");
    printf("\n");

}

int main(){
    n = 6;

    graph['a'].adj.push_back('b');
    graph['b'].adj.push_back('a');
    //graph['b'].adj.push_back('d');
    //graph['f'].adj.push_back('a');
    //graph['d'].adj.push_back('c');

    indegree['a'] = 1;
    indegree['b'] = 1;
    //indegree['c'] = 1;
    //indegree['d'] = 2;
    //indegree['e'] = 0;
    //indegree['f'] = 0;

    topo_sort();

}
