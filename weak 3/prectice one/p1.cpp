// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;
// vector<int> dist(N, INF);
// bool visited[N];
// vector<pair<int, int>> adj[N];

// void dijstra(int source)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     dist[source] = 0;
//     pq.push({dist[source], source});

//     while (!pq.empty())
//     {
//         pair<int, int> f = pq.top();
//         pq.pop();

//         int seclectNode = f.second;

//         for (auto child : adj[seclectNode])
//         {
//             int vartex = child.first;
//             int edgeCost = child.second;

//             if (visited[vartex])
//                 continue;
//             visited[seclectNode] = true;

//             if (dist[vartex] > dist[seclectNode] + edgeCost)
//             {
//                 dist[vartex] = dist[seclectNode] + edgeCost;
//                 pq.push({dist[vartex], vartex});
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
//         adj[children].push_back({parent, weighted});
//     }

//     int source, d;
//     cin >> source >> d;

//     dijstra(source);

//     cout << source << "-> "
//          << " to " << d << " -> "
//          << " : " << dist[d] << " ";
//     return 0;
// }

// ----------------------------------------------------------------------->

#include <bits/stdc++.h>
using namespace std;

//-------------- galbally value diclar korlam ------------>

typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pii> g[N];
vector<int> dist(N, INF);
bool visited[N];
int parent[N];

// -------------------- function diclar korlam ---------->

void dijstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        pii f = pq.top();
        pq.pop();

        int selectNode = f.second;

        for (auto child : g[selectNode])
        {
            int vartex = child.first;
            int edgeCost = child.second;

            if (visited[vartex] == true)
                continue;
            visited[selectNode] = true;

            if (dist[vartex] > dist[selectNode] + edgeCost)
            {
                dist[vartex] = dist[selectNode] + edgeCost;
                pq.push({dist[vartex], vartex});
                parent[vartex] = selectNode;
            }
        }
    }
}

int main()
{
    //------- input -------->
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // ----------- distance of source print korlam ----------->
    int source, d;
    cin >> source >> d;
    dijstra(source);
    cout << dist[d] << " " << endl;
    // ------------ shortest path ber korlam ----------------->
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