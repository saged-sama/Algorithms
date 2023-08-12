#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 105;
int minDist[N][N];

void floydWarshall(int n, int m){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			minDist[i][j] = LLONG_MAX;
		}
		minDist[i][i] = 0;
	}
	
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		minDist[u][v] = min(minDist[u][v], w);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(minDist[i][k] != LLONG_MAX and minDist[k][j] != LLONG_MAX){
					minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
				}
			}
		}
	}
}

signed main()
{
	int n, m; cin >> n >> m;
	floydWarshall(n, m);
	for(int i = 1; i <= n; i++){
		if(minDist[1][i] == LLONG_MAX) cout << 30000 << " ";
		else cout << minDist[1][i] << " ";
	}
	cout << "\n";
	return 0;
}
