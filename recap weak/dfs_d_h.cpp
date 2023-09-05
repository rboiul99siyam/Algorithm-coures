#include <bits/stdc++.h>
using namespace std;

// -------------- const vaue declar korlam ------------->
const int N = 1e5 + 10;
bool visited[N];
vector<int> g[N];
int depth[N];
int height[N];

// --------------- fucntion ta declar kore dilam ------------->

void dfs(int parent)
{
    visited[parent] = true;
    for (int child : g[parent])
    {
        if (visited[child] == true)
            continue;
        depth[child] = depth[parent] + 1;
        dfs(child);
        height[parent] = max(height[parent], height[child] + 1);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << " Depth " << i << " : ";
        cout << "->" << depth[i] << endl;
    }

    cout << " *****************************************************" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Height " << i << " : ";
        cout << "->" << height[i] << endl;
    }

    return 0;
}

/*
sample input :
5
5
1 2
1 3
2 3
3 4
4 5

*/