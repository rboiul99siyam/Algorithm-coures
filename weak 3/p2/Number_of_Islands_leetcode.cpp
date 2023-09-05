#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<string> g;
bool visited[N][N];

int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j)
{
    if (!isValid)
        return;
    if (visited[i][j])
        return;
    if (g[i][j] == '0')
        return;

    visited[i][j] = true;
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i - 1, j);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        g.push_back(x);
    }

    int isLand = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '0')
                continue;
            if (visited[i][j] == true)
                continue;
            dfs(i, j);
            isLand++;
        }
    }
    cout << isLand;
    return 0;
}

/* 

  "1","1","1","1","0"
  "1","1","0","1","0"
  "1","1","0","0","0"
  "0","0","0","0","0"

  1.1.1.1.0
  1.1.0.1.0
  1.1.0.0.0
  0.0.0.0.0


 */