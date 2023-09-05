#include <bits/stdc++.h>
using namespace std;

// -------------- const value gula ke declar korlam ------------>
typedef pair<int, int> pii;
const int N = 1e3 + 5;
bool visited[N][N];
int dis[N][N];
vector<pii> path;
int n, m;
// ---------------------------- inValid check korlam ------------>
bool isvaild(int i, int j)
{
    if (i >= 0 && i < n && j >= 0, j < m)
        return true;
    else
        return false;
}
//--------------------------- void declar korlam --------------->
void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pii parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pii p = path[i];
            int ci = pi + p.first;
            int cj = pj + p.second;

            if (isvaild(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci, cj});
                dis[ci][cj] = dis[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    char ar[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

