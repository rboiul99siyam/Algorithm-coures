#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
bool vistied[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vistied[s] = true;
    level[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (vistied[v] == true)
                continue;
            q.push(v);
            vistied[v] = true;
            level[v] = level[u] + 1;
        }
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
    while (k--)
    {
        int f, d;
        cin >> f >> d;

        for (int i = 0; i < n; i++)
        {
            vistied[i] = false;
            level[i] = 0;
        }
        bfs(f);
         if (vistied[d])
            {
                cout << level[d] << endl;
               
            }
            else
            {
                cout << "-1" << endl;
            }
    }

    return 0;
}
