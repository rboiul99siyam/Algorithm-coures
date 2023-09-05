/*

7
5
1 2
1 3
2 3
4 5
6 7

*/

#include <bits/stdc++.h>
using namespace std;

//--------------- const declar ------------->
const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];

// ---------------- function declar -------------->

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
        }
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

    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
            continue;
        bfs(i);
        cc++;
    }
    cout << cc << endl;
    return 0;
}
