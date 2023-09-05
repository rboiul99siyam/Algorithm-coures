#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pir;
const int N = 1e3 + 10;
int  visited[N][N];
int level[N][N];
vector<string> g;
vector<pir> distanation = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pir parent[N][N];
int n, m;

bool isVaild(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pir> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pir upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto dist : distanation)
        {
            int ni = i + dist.first;
            int nj = j + dist.second;

            if (isVaild(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#')
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
                si = j, sj = j;
            if (x[j] == 'B')
                di = i, dj = j;
        }
        g.push_back(x); // value push kore dilam
    }

    bfs(si, sj); // distance of source

    cout << level[di][dj] << endl;
    return 0;
}
/*
########
#.A#...#
#.##.#B#
#......#
########
*/