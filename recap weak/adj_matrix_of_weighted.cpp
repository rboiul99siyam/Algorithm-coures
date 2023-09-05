#include <bits/stdc++.h>
using namespace std;

// -------------------- coonst value ---------------------->
const int N = 1e3 + 10;
int adjmat[N][N];

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjmat[u][v] = w;
        adjmat[v][u] = w;
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
