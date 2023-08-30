#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> graph[N];
int h[N];
int minDist[N][N];
bool visited[N];

bool bellmanford(int src, int n)
{
    h[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto [u, v, w] : edges)
        {
            if (h[u] != INT_MAX and h[v] > h[u] + w)
            {
                h[v] = h[u] + w;
            }
        }
    }
    for (auto [u, v, w] : edges)
    {
        if (h[u] != INT_MAX and h[v] > h[u] + w)
        {
            return true;
        }
    }
    return false;
}

void dijkstra(int src)
{
    for (int i = 0; i < N; i++)
    {
        minDist[src][i] = INT_MAX;
        visited[i] = false;
    }
    minDist[src][src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, src});

    while (q.empty() == false)
    {
        auto p = q.top();
        q.pop();

        int u = p.second;
        if (visited[u])
            continue;
        visited[u] = true;

        for (auto edge : graph[u])
        {
            int v = edge.second;
            int w = edge.first;

            if (minDist[src][u] != INT_MAX and minDist[src][v] > minDist[src][u] + w)
            {
                minDist[src][v] = minDist[src][u] + w;
                q.push({minDist[src][v], v});
            }
        }
    }
}

bool johnson(int n)
{
    for (int i = 0; i < N; i++)
    {
        h[i] = INT_MAX;
        graph[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        edges.push_back(make_tuple(n + 1, i, 0));
    }
    if (bellmanford(n + 1, n))
    {
        return false;
    }

    for (auto [u, v, w] : edges)
    {
        if (u and v)
            graph[u].push_back({w + h[u] - h[v], v});
    }

    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (minDist[i][j] != INT_MAX)
            {
                minDist[i][j] = minDist[i][j] + h[j] - h[i];
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
    }
    if (!johnson(n))
    {
        cout << "Negative cycle\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (minDist[i][j] == INT_MAX)
                {
                    cout << "infinity ";
                }
                else
                {
                    cout << minDist[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
