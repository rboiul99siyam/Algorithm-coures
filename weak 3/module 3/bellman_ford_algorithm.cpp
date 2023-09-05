#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
int dist[N];
vector<pair<int, int>> g[N];

void bellman_ford(int source, int nodes)
{
    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    for (int i = 1; i <= nodes; i++) // n -1 loop useing
    {
        for (int u = 1; u <= nodes; u++) // number node 
        {
            for (auto child : g[u]) // g[u] eta hole parents tai parent child gula k khuje ber kore relax kore dilam 
            {
                int vartex = child.first;
                int edgeCost = child.second;

                if (dist[u] != INF && dist[vartex] > dist[u] + edgeCost) // relaxation kore dilam 
                {
                    dist[vartex] = dist[u] + edgeCost;
                }
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    bellman_ford(1, nodes);
    for (int i = 1; i <= nodes; i++)
    {
        cout << "distance  " << i;
        cout << ": " << dist[i] << endl;
    }
    return 0;
}

