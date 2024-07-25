#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<vector<tuple<int, int, int>>> G(N+5);

int primMST(int m) {
    vector<bool> visited(m, false);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int totalWeight = 0;

    pq.push(make_tuple(0, 0, 0));

    while (!pq.empty()) {
        auto [weight, u, prev] = pq.top();
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;
        totalWeight += weight;
        for (auto[from, v, w] : G[u]) {
            if (!visited[v])
                pq.push(make_tuple(w, v, u));
        }
    }
    return totalWeight;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> wt >> u >> v;
        G[u].emplace_back(u, v, wt);
        G[v].emplace_back(v, u, wt);
    }

    int ans = primMST(m);
    cout << ans << "\n";
  }
}
// 9 14
// 1 7 6
// 2 8 2
// 2 6 5
// 4 0 1
// 4 2 5
// 6 8 6
// 7 2 3
// 7 7 8
// 8 0 7
// 8 1 2
// 9 3 4
// 10 5 4
// 11 1 7
// 14 3 5
// ans = 37