#include <bits/stdc++.h>
using namespace std;

//------------ const vaule declar korlam -------------->
const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];
int level[N];
int parent[N];

//----------- function declar korlam --------------------->

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int child : g[u])
        {
            if (visited[child] == true)
                continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[u] + 1;
            parent[child] = u;
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

    // bfs(1);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Level " << i << " : ";
    //     cout << "->" << level[i] << endl;
    // }

    int s, d;
    cin >> s >> d;
    bfs(s);

    int cnt = d;
    vector<int> path;
    while (cnt != 0)
    {
        path.push_back(cnt);
        cnt = parent[cnt];
    }

    reverse(path.begin(), path.end());

    for (int l : path)
        cout << " -> " << l << " " << endl;

    return 0;
}

/*
5
5
1 2
1 3
2 3
3 4
4 5
*/