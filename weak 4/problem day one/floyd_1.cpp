#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int dist[N][N];
int n;

void floyd_inliazation()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    floyd_inliazation();

    return 0;
}