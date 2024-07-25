#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int N = 1e5 + 7;

vector<pair<int, int>> adj[N];
bool visited[N];
lli minVisitCost[N];
int parent[N];

void djkstra(int source_node){
    for(int i = 1; i <= N; i++){
        parent[i] = -1;
        minVisitCost[i] = LONG_LONG_MAX;
        visited[i] = false;
    }
    minVisitCost[source_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, source_node});
    
    while(q.empty() == false){
        auto pr = q.top();
        q.pop();

        int current_node = pr.second;

        if(visited[current_node]) continue;
        visited[current_node] = true;

        for(auto edge: adj[current_node]){
            int destination_node = edge.second;
            int weight = edge.first;

            if(minVisitCost[destination_node] > minVisitCost[current_node] + weight){
                minVisitCost[destination_node] = minVisitCost[current_node] + weight;
                parent[destination_node] = current_node;
                q.push({minVisitCost[destination_node], destination_node});
            }
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    djkstra(1);

    if(parent[n] == -1){
        cout << -1 << "\n";
    }
    else{
        vector<int> path;
        while(n > 0){
            path.push_back(n);
            n = parent[n];
        }
        
        reverse(path.begin(), path.end());

        for(auto node: path){
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}