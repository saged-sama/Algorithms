#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5;

int low[N];
int disc[N];
vector<pair<int, int>> bridge;
int ttime = 0;
vector<int> graph[N];

void dfsBridge(int u, int parent){
    int children = 0;
    low[u] = disc[u] = ++ttime;
    for(auto v: graph[u]){
        if(v == parent) continue;
        if(!disc[v]){
            children++;
            dfsBridge(v, u);
            if(disc[u] < low[v]){
                bridge.push_back({u, v});    
            }
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], disc[v]);
        }   
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(!disc[i]){
            dfsBridge(i, i);
        }
    }
    for(auto b: bridge){
        cout << b.first << " " << b.second << "\n";
    }
    return 0;
}
