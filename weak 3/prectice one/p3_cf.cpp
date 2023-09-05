#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const long long int INF = 1e18;
vector<pair<int, int>> g[N];
int nodes, edges;
long long int dist[N];

bool visited[N];

void dijstra(int source)
{
    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        pair<int, int> f = pq.top();
        pq.pop();
        int selectNode = f.second;

        for (auto child : g[selectNode])
        {
            int edgeCost = child.first;
            int v = child.second;

            if (visited[selectNode])
                continue;

            visited[selectNode] = true;
            if (dist[selectNode] + edgeCost < dist[v])
            {
                dist[v] = dist[selectNode] + edgeCost;
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
        int p, c, w;
        cin >> p >> c >> w;
        g[p].push_back({c, w});
        g[c].push_back({p, w});
    }
    // int src = 1;
    int s,d;
    cin>>s>>d;
    dijstra(s);
    cout<<dist[d]<<" ";

    return 0;
}