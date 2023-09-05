// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<int> adj[N];
// bool visited[N];
// int level[N];
// int prent[N];
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;
//     level[s] = 0;
//     prent[s] = 0;

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         for (int v : adj[u])
//         {
//             if (visited[v] == true)
//                 continue;
//             q.push(v);
//             visited[v] = true;
//             level[v] = level[u] + 1;
//             prent[v] = u;
//         }
//     }
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int s, d;
//     cout << "Enter your source and destanation : " << endl;
//     cin >> s >> d;

//     bfs(s);
//     cout << "Destancetion : " << level[d] << endl;

//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cout << "parent of " << i << ": " << prent[i] << endl;
//     // }
//     int crnt = d;
//     vector<int> path;
//     while (crnt != 0)
//     {
//         path.push_back(crnt);
//         crnt = prent[crnt];
//     }
//     reverse(path.begin(), path.end());

//     for (int node : path)
//     {
//         cout << node << " ";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
    }
}
int main()
{
    int n, m;
    cout << "Enter number of node and edge : " << endl;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, d;
    cout << "Enter your source and dastanation : " << endl;
    cin >> s >> d;
    bfs(s);
    cout << "destance : " << level[d] << endl;

    int curent = d;
    vector<int> path;

    while (curent != -1)
    {
        path.push_back(curent);
        curent = parent[curent];
    }
    sort(path.begin(), path.end());
    for (int node : path)
    {
        cout << node << " " << endl;
    }

    return 0;
}

