#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int nodes, edges;
long long int INF = 1e18;
long long int dist[N];
bool visited[N];
void dijstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        pair<int, int> f = pq.top();
        pq.pop();

        int secletNode = f.second;

        if (visited[secletNode])
            continue;
        visited[secletNode] = true;

        for (auto child : adj[secletNode])
        {
            int edgeCost = child.first;
            int v = child.second;

            if (dist[secletNode] + edgeCost < dist[v])
            {
                dist[v] = dist[secletNode] + edgeCost;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src = 1;

    dijstra(src);
    for(int i=1;i<=nodes;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}