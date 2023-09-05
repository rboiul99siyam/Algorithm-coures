#include <bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int> adj[N];
bool vistied[N];

void dfs(int u)
{
    vistied[u] = true;
    for (int v : adj[u])
    {
        if (vistied[v] == true)
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

    int k;
    cin >> k;
    int res;
    for (int i = 0; i < n; i++)
    {
        if (vistied[i] == true)
            continue;
        dfs(i);
        res = adj[k].size();
    }

    cout << res << endl;

    return 0;
}