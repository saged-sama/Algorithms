#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
int graph[N][N];
int residual_graph[N][N];
bool visited[N];
int parent[N];

bool AugmentingPath(int source, int sink, int n){
    for(int i = 0; i < N; i++){
        visited[i] = false;
        parent[i] = i;
    }

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0; v < n; v++){
            if(visited[v] == false and residual_graph[u][v] > 0){
                if(v == sink){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int EdmondsKarp(int source, int sink, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            residual_graph[i][j] = graph[i][j];
        }
    }

    int maximum_flow = 0;

    while(AugmentingPath(source, sink, n)){
        int bottleneck = INT_MAX;
        for(int v = sink; v != source; v = parent[v]){
            int u = parent[v];
            bottleneck = min(bottleneck, residual_graph[u][v]);
        }

        for(int v = sink; v != source; v = parent[v]){
            int u = parent[v];
            residual_graph[u][v] -= bottleneck;
            residual_graph[v][u] += bottleneck;
        }
        maximum_flow += bottleneck;
    }
    return maximum_flow;
}

int main()
{
    int n; cin >> n;
    int m; cin >> m;
    for(int i = 1; i <= m; i++){
        int u, v, c; cin >> u >> v >> c;
        graph[u][v] = c;
    }
    int sink, source;
    cin >> source >> sink;
    cout << EdmondsKarp(source, sink, n) << "\n";
    return 0;
}