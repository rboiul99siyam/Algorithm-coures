#include <bits/stdc++.h>
using namespace std;

// ----------------const value declar korlam ------------------->
const int N = 1e3 + 10;
bool visited[N][N];
vector<string> g;
int n, m;
//-------------- isValid check korlam ------------------------>

bool isValid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    else
        return false;
}

// ------------ void function declar korlam ------------------->

void dfs(int i, int j)
{
    if (!isValid(i, j))
        return;
    if (visited[i][j] == true)
        return;
    if (g[i][j] == '#')
        return;
    visited[i][j] = true;
 
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
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

    int cc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '#')
                continue;
            if (visited[i][j] == true)
                continue;
            dfs(i, j);
            cc++;
        }
    }

    cout << cc;
    return 0;
}

/*
########
#..#...#
####.#.#
#..#...#
########
*/