#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e5+7;
vector<tuple<int, int, int>> edges;
bool visited[N];
int minDistance[N];

void bellmanFord(int source, int n){
	for(int i = 0; i < N; i++){
		minDistance[i] = LLONG_MAX;
	}
	minDistance[source] = 0;
	
	for(int u = 1; u <= n-1; u++){
		for(auto edge: edges){
			auto [u, v, w] = edge;
			if(minDistance[u] != LLONG_MAX) minDistance[v] = min(minDistance[v], minDistance[u] + w);
		}
	}
	
	for(auto edge: edges){
		auto [u, v, w] = edge;
		if(minDistance[u] != LLONG_MAX and minDistance[v] > minDistance[u] + w){
			cout << "CYCLE FOUND!!!\n";
		}
	}
}

signed main()
{
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	bellmanFord(1, n);
	for(int i = 1; i <= n; i++){
		if(minDistance[i] == LLONG_MAX) cout << "unreachable ";
		else cout << minDistance[i] << " ";
	}
	cout << "\n";
	return 0;
}
