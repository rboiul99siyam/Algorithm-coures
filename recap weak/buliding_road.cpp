#include <bits/stdc++.h>
using namespace std;

// ---------------- const value declar koralm ------------>
const int N = 1e5 + 10;
bool visited[N];
vector<int> g[N];

// -------------------- void function declar korlam -------------------->

void dfs(int parent)
{
    visited[parent] = true;

    for (int child : g[parent])
    {
        if (visited[child] == true)
            continue;
        visited[child] = true;
        dfs(child);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> road;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
            continue;
        road.push_back(i);
        dfs(i);
    }

    cout << road.size() - 1 << endl;

    for (int i = 0; i < road.size() -1; i++)
    {
        cout << road[i] << " " << road[i + 1] << endl;
    }

    return 0;
}