#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
vector<map<int, int>> graph(N);
vector<map<int, int>> residual_graph(N);
bool visited[N];
int parent[N];

bool AugmentingPath(int source, int sink){
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

        for(auto edge: residual_graph[u]){
            int v = edge.first;
            int c = edge.second;
            if(visited[v] == false and c > 0){
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

int EdmondsKarp(int source, int sink){
    residual_graph = graph;

    int maximum_flow = 0;

    while(AugmentingPath(source, sink)){
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
    cout << EdmondsKarp(source, sink) << "\n";
    return 0;
}
