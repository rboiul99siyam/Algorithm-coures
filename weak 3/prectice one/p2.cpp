// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;
// bool visited[N];
// vector<pair<int, int>> adj[N];
// vector<int> dist(N, INF);

// void dijstra(int source)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     dist[source] = 0;
//     pq.push({dist[source],source});
//     while (!pq.empty())
//     {
//         pair<int, int> f = pq.top();
//         pq.pop();

//         int secletNode = f.second;

//         for (auto child : adj[secletNode])
//         {
//             int vartexOrnode = child.first;
//             int edgeCost = child.second;

//             if (visited[vartexOrnode])
//                 continue;
//             visited[secletNode] = true;

//             if (dist[vartexOrnode] > dist[secletNode] + edgeCost)
//             {
//                 dist[vartexOrnode] = dist[secletNode] + edgeCost;
//                 pq.push({dist[vartexOrnode], vartexOrnode});
//             }
//         }
//     }
// }
// int main()
// {
//     int nodes, edges;
//     cin >> nodes >> edges;
//     for (int i = 0; i < edges; i++)
//     {
//         int parent, children, weighted;
//         cin >> parent >> children >> weighted;
//         adj[parent].push_back({children, weighted});
//     }

//     int source, d;
//     cin >> source >> d;
//     dijstra(source);
//     cout << "->" << dist[d] << " ";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// ---------- galbally value diclar korlam ------------->
typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pii> g[N];
bool visited[N];
vector<int> dist(N, INF);
int parent[N];

// ---------- function declared korlam -------->

void dijstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        pii f = pq.top();
        pq.pop();

        int selcetNode = f.second;

        for (auto child : g[selcetNode])
        {
            int vartex = child.first;
            int edgeCost = child.second;

            if (visited[vartex])
                continue;
            visited[selcetNode] = true;

            if (dist[vartex] > dist[selcetNode] + edgeCost)
            {
                dist[vartex] = dist[selcetNode] + edgeCost;
                pq.push({dist[vartex], vartex});
                parent[vartex] = selcetNode;
            }
        }
    }
}

int main()
{

    // --------- input nilam ------------>
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    int source, d;
    cin >> source >> d;
    dijstra(source);
    cout << dist[d] << " " << endl;

    // --------------shortest path ---------------->

    int crnt = d;
    vector<int> path;

    while (crnt != 0)
    {
        path.push_back(crnt);
        crnt = parent[crnt];
    }

    reverse(path.begin(), path.end());

    for (int Nodes : path)
    {
        cout << Nodes << " -> ";
    }

    return 0;
}