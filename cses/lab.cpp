#include <bits/stdc++.h>
using namespace std;

// ---------- const value declar korlam --------------->

typedef pair<int, int> pii;
const int N = 1e3;
int visited[N][N];
vector<string> g;
vector<pii> dist = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pii parent[N][N];
int level[N][N];
int n, m;
// -------------- isvalid check korte hobe ----------------->

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
// ------------ function value ------------------>

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});

    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii f = q.front();
        q.pop();

        int i = f.first;
        int j = f.second;

        for (auto d : dist)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (!isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] == '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'A')
                si = i, sj = j;
            if (x[j] == 'B')
                di = i, dj = j;
        }
        g.push_back(x);
    }

    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout << "YES" << endl;
        cout << level[di][dj];
    }
    else
    {
        cout << "-1";
        return 0;
    
    }
}