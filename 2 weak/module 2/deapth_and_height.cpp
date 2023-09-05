// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<int> adj[N];

// bool visited[N];
// int deatph[N];
// int height[N];
// void dfs(int u)
// {
//     visited[u] = true;
//     for (int v : adj[u])
//     {
//         if (visited[v] == true)
//             continue;
//         deatph[v] = deatph[u] + 1;
//         dfs(v);
//         // now we can determin the height of u
//         // mathod 1:
//         // if (height[v] + 1 > height[u])
//         // {
//         //     height[u] = height[v] + 1;
//         // }
//         height[u] = max(height[u], height[v] + 1);
//     }
// }
// int main()
// {
//     int n, m;
//     cout << "Number of node Of number of edge" << endl;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cout << "u"
//              << " "
//              << "v" << endl;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     dfs(1);

//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Depth of Node " << i << " " << deatph[i] << endl;
//     }

//     cout << "******************************************************" << endl;
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "height of Node " << i << " " << height[i] << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == true)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v);

        height[u] = max(height[u], height[v] + 1);
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

    for (int i = 1; i <= n; i++)
    {
        cout << "node   " << i << " : "
             << "depth" << depth[i] << endl;
    }

    cout << "***********************************************************" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Node   " << i << ": "
             << "height" << height[i] << endl;
    }
    return 0;
}