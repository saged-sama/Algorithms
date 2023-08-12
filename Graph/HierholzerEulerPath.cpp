#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];

bool hasEulerPath(int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(adj[i].size() & 1){
            cnt++;
        }
    }
    if(cnt == 0 or cnt == 2) return true;
    return false;
}

void find_path(int start, vector<int>& ans) {
    while(!adj[start].empty()) {
        int v = adj[start].back();
        adj[start].pop_back();

        auto it = find(adj[v].begin(), adj[v].end(), start);
        adj[v].erase(it);
                
        find_path(v, ans);

    }
    ans.push_back(start);
}

int main(){
    int n, m; cin >> n >> m;

    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool euler = hasEulerPath(n);

    if(!euler) cout<<"No euler path\n";
    else {
        vector<int> ans;
        int start = 0;
        for(int i = 0; i < n; i++){
            if(adj[i].size() & 1){
                start = i;
                break;
            }
        }

        find_path(start, ans);

        reverse(ans.begin(),ans.end());

        for(auto v: ans){
            cout << v << " ";
        }
        cout<<'\n';

    }

    return 0;
}
