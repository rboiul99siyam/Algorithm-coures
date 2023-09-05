
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pii> g[N];
vector<int> dist(N, INF);
bool visited[N];

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        pii f = pq.top();
        pq.pop();
        int sN = f.second;

        if (visited[sN])
            continue;
        visited[sN] = true;

        for (pii child : g[sN])
        {
            int vartex = child.first;
            int ed = child.second;

            if (dist[vartex] > dist[sN] + ed)
            {
                dist[vartex] = dist[sN] + ed;
                pq.push({dist[vartex], vartex});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << "30000"
                 << " ";
        else
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}
