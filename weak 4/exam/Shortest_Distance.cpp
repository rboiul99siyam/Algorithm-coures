#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int dist[N][N];

int n, e;

void floyed_wallshal()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }
}

int main()
{
    cin >> n >> e;
    floyed_wallshal();

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[j][k];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int result = dist[x][y];
        if (result == INF)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << dist[x][y] << endl;
        }
    }

    return 0;
}