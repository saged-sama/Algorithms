#include <bits/stdc++.h>
using namespace std;

void union_set(int u, int v, vector<int>& parent){
    parent[u] = parent[v];
}

int find_set(int u, vector<int>& parent){
    if(u == parent[u]){
        return u;
    }
    return find_set(parent[u], parent);
}

int kruskal_minimum_spanning_tree(vector<pair<int, pair<int, int>>>& edges, vector<int>& parent, vector<pair<int, pair<int, int>>>& minimum_spanning_tree){
    int n = parent.size();
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    int totalWeight = 0;

    for(auto edge: edges){
        int parent_of_u = find_set(edge.second.first, parent);
        int parent_of_v = find_set(edge.second.second, parent);
        if(parent_of_u != parent_of_v){
            union_set(parent_of_u, parent_of_v, parent);
            minimum_spanning_tree.push_back(edge);
            totalWeight += edge.first;
        }
    }
    return totalWeight;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    vector<pair<int, pair<int, int>>> minimum_spanning_tree;
    vector<int> parent(n);

    for(int i = 1; i <= m; i++){
        int w, u, v;
        cin >> w >> u >> v;
        edges.push_back({w, {u, v}});
    }
    cout << kruskal_minimum_spanning_tree(edges, parent, minimum_spanning_tree) << "\n";
    return 0;
}
