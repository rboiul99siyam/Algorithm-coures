#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> g[N];
bool visited[N];
int level[N];
int prt[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    prt[s] = 0;

    while (!q.empty())
    {
        int selcetNode = q.front();
        q.pop();

        for (int child : g[selcetNode])
        {
            if (visited[child])
                continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[selcetNode] + 1;
            prt[child] = selcetNode;
        }
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int parent, children;
        cin >> parent >> children;
        g[parent].push_back(children);
        // g[children].push_back(parent);
    }

    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << level[d] << " ";

    int crt = d;
    vector<int> path;
    while (crt != 0)
    {
        path.push_back(crt);
        crt = prt[crt];
    }
    sort(path.begin(), path.end());

    for (int nods : path)
    {
        cout << nods << " ";
    }
    return 0;
}