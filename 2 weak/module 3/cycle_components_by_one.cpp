// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 7;
// vector<int> adj[N];
// bool visited[N];
// bool dfs(int u, int p = -1)
// {
//     bool cycleExits = false;
//     visited[u] = true;
//     for (int v : adj[u])
//     {
//         if (v == p)
//             continue;

//         if (visited[v] == true)
//             return true;
//         dfs(v);
//         cycleExits = cycleExits || dfs(v, u);
//     }
//     return cycleExits;
// }
// int main()
// {

//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v); // directed
//         adj[v].push_back(u); // undirected
//     }
//     if (dfs(1))
//     {
//         cout << "cycle decrted!" << endl;
//     }
//     else
//     {
//         cout << "No decrted!" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
    bool cycleEixt = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v] == true)
            return true;

        dfs(v);
        cycleEixt = cycleEixt || dfs(v, u);
    }
    return cycleEixt;
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

    if (dfs(1))
    {
        cout << "cycle directed !" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }
    return 0;
}