#include <bits/stdc++.h>
using namespace std;

// ---------------- const value declar korlam ---------------->
const int N = 1e3 + 1;
int adjmat[N][N];
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) // number  of edge er upor loop  chaliye dilam 
    {
        int u, v;
        cin >> u >> v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/* 
4 4
1 2
1 3
1 4
4 3
 */