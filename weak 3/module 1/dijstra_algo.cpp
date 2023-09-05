// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// const int INF = 1e9 + 10;   // Initialization of infinity
// typedef pair<int, int> pii; // Pair of integers
// vector<pii> adj[N];         // Adjacency list
// vector<bool> visited(N);    // Array to mark visited vertices
// vector<int> dist(N, INF);   // Array to store distances

// void dijstra(int s)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     dist[s] = 0;           // Distance to source vertex is 0
//     pq.push({dist[s], s}); // Push source vertex with distance into the priority queue

//     while (!pq.empty())
//     {
//         int u = pq.top().second; // Get the vertex with the smallest distance
//         pq.pop();

//         visited[u] = true; // Mark the vertex as visited

//         for (pii vpii : adj[u]) // Iterate through adjacent vertices
//         {
//             int v = vpii.first;  // Get the adjacent vertex
//             int w = vpii.second; // Get the weight of the edge

//             if (visited[v] == true)
//                 continue; // Skip if the vertex is already visited

//             if (dist[v] > dist[u] + w)
//             {
//                 dist[v] = dist[u] + w; // Update the distance if a shorter path is found
//                 pq.push({dist[v], v}); // Push the updated distance and vertex into the priority queue
//             }
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m; // Read the number of vertices and edges

//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;       // Read an edge (u, v) with weight w
//         adj[u].push_back({v, w}); // Add the edge to the adjacency list
//         adj[v].push_back({u, w}); // Since the graph is undirected, add the reverse edge as well
//     }

//     dijstra(1); // Run Dijkstra's algorithm with source vertex 1

//     for (int i = 1; i <= n; i++)
//     {
//         cout << "distance  " << i << ": ";
//         cout << dist[i] << " " << endl; // Print the calculated distances
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, int> pii;
// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;
// vector<pii> g[N];
// vector<bool> visited(N);
// vector<int> dist(N, INF);

// void dijstra(int s)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     dist[s] = 0;
//     pq.push({dist[s], s});

//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();
//         visited[u] = true;

//         for (pii vpii : g[u])
//         {
//             int v = vpii.first;
//             int w = vpii.second;

//             if (visited[v] == true)
//                 continue;

//             if (dist[v] > dist[u] + w)
//             {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     dijstra(1);

//     for (int i = 1; i <= n; i++)
//     {
//         cout << " destance  " << i << ": ";
//         cout << dist[i] << " " << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
bool visited[N];
int parent[N];

void dijstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int selectNode = pq.top().second;
        pq.pop();
        visited[selectNode] = true;

        for (auto chlid : g[selectNode])
        {
            int vartex = chlid.first;
            int egdeCost = chlid.second;

            if (visited[vartex])
                continue;

            if (dist[vartex] > dist[selectNode] + egdeCost)
            {
                dist[vartex] = dist[selectNode] + egdeCost;
                pq.push({dist[vartex], vartex});
                parent[vartex] = selectNode;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // g[v].push_back({u, w});
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "distance   " << i << ": ";
    //     cout << " -> " << dist[i] << " " << endl;
    // }
    int s, d;
    cin >> s >> d;
    dijstra(s);

    int crnt = d;
    vector<int>paht;
    while(crnt != 0)
    {
       paht.push_back(crnt);
       crnt = parent[crnt];

    }

    reverse(paht.begin(),paht.end());

    for(int Nodes : paht)
    {
        cout<<Nodes<<" ";
    }

    return 0;
}