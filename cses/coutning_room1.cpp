#include <bits/stdc++.h>
using namespace std;

// ------------------- const value galbal declar korlam -------------->

const int N = 1e3;
vector<string> g;
bool visited[N][N];
int n, m;
//----------- isValid check korlam ------------->

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// --------------- fucntion call korlam ----------------->

void dfs(int i, int j)
{
    if (isValid(i, j) == false)
        return;
    if (visited[i][j])
        return;
    if (g[i][j] == '#')
        return;

    visited[i][j] = true;
    // if (!isValid(i, j) || visited[i][j] || g[i][j] == '#')
    //     return;

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

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '#')
                continue;
            if (visited[i][j] == true)
                continue;
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}