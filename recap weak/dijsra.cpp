#include <bits/stdc++.h>
using namespace std;

//--------- const value declar korlam ---------------------->
const int N = 1e5 + 10;
typedef pair<int, int> pi;
bool visited[N];
int dist[N];
vector<pi> g[N];
int parent1[N];
int n, e;
//------------ function declar korlam ------------------------>

void dijstra(int source)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    dist[source] = 0;

    pq.push({dist[source], source});

    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();

        int childNode = parent.second;

        for (auto child : g[childNode])
        {
            int vartex = child.first;
            int edgeCost = child.second;

            if (visited[childNode] == true)
                continue;

            if (dist[vartex] > dist[childNode] + edgeCost)
            {
                dist[vartex] = dist[childNode] + edgeCost;
                pq.push({dist[vartex], vartex});
                parent1[vartex] = childNode;
            }
        }
    }
}

int main()
{

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int s, d;
    cin >> s >> d;
    dijstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << " dist " << i << " : ";
        cout << "->" << dist[i] << endl;
    }
    int crnt = d;
    vector<int> path;
    while (crnt != 0)
    {
        path.push_back(crnt);
        crnt = parent1[crnt];
    }

    reverse(path.begin(), path.end());

    for (int p : path)
    {
        cout << " -> " << p << " ";
    }

    return 0;
}

/*

sample input :
5 6
1 2 10
1 5 15
1 4 2
5 4 3
4 3 5
2 3 1
sample output:
 dist 1 : ->0
 dist 2 : ->8
 dist 3 : ->7
 dist 4 : ->2
 dist 5 : ->5

*/