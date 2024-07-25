#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5;

int low[N];
int disc[N];
bool articulationPoint[N];
int ttime = 0;
vector<int> graph[N];

int dfsAP(int u, int parent){
    int children = 0;
    low[u] = disc[u] = ++ttime;
    for(auto v: graph[u]){
        if(v == parent) continue;
        if(!disc[v]){
            children++;
            dfsAP(v, u);
            if(disc[u] <= low[v]){
                articulationPoint[u] = true;    
            }
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], disc[v]);
        }   
    }
    return children;
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
            articulationPoint[i] = (dfsAP(i, i) > 1);
        }
    }
    for(int i = 0; i < n; i++){
        if(articulationPoint[i]) cout << i << "\n";
    }
    return 0;
}