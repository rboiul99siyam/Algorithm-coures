#include <bits/stdc++.h>
using namespace std;

// ----------- galbally value declar korlam ----------------->
typedef pair<int, int> pii;
const int N = 1e3 + 10;
int visited[N][N];
vector<string> g;
int level[N][N];
pii parent[N][N];
vector<pii> dist = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int row, cul;
// --------------- visited check korlam ------------------>
bool isValid(int i, int j)
{
    return (i >= 0 && i < row && j >= 0 && j < cul);
}

// ------------ function declar korlam ---------------->

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

        int row_i = f.first;
        int cul_j = f.second;

        for (auto d : dist)
        {
            int row_ni = row_i + d.first;
            int cul_nj = cul_j + d.second;

            if (isValid(row_ni, cul_nj) && !visited[row_ni][cul_nj] && g[row_ni][cul_nj] != 'x')
            {
                q.push({row_ni, cul_nj});
                visited[row_ni][cul_nj] = true;
                level[row_ni][cul_nj] = level[row_i][cul_j] + 1;
                parent[row_ni][cul_nj] = {row_i, cul_j};
            }
        }
    }
}
int main()
{  

    cin >> row >> cul;
    int si, sj, di, dj;
    for (int i = 0; i < row; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < cul; j++)
        {
            if (x[j] == 's')
                si = i, sj = j;
            if (x[j] == 'e')
                di = i, dj = j;
        }

        g.push_back(x);
    }
    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout << level[di][dj] << " ";
    }
    else
    {
        cout << "-1";
        return 0;
    }
    return 0;
}