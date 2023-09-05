// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<int> adj[N];
// bool visted[N];
// void dfs(int u)
// {
//     // section 1: actions just after entering node u
//     visted[u] = true;
//     cout << "visting node : " << u << endl;
//     for (int v : adj[u])
//     {
//         // section 2 : actions before entering a new neighbor
//         if (visted[v] == true)
//             continue;
//         dfs(v);
//         // section 3 : actions bofore exiting a neighbor
//     }
//     // section 4 : actions before exiting a node u
// }
// int main()
// {
//     int n, m;
//     cout << "Number of node and number edge :" << endl;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v); // directed graph
//         adj[v].push_back(u); // undirected graph
//     }

//     dfs(1);

//     cout << "visiting Array " << endl;

//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Node : " << i << " status " << visted[i] << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    cout << "visted " << u << endl;
    for (int v : adj[u])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << "*********************************" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Node : " << i << " visited node " << visited[i] << endl;
    }
    return 0;
}