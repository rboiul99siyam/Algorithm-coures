#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int dp[N][N];

int knapsack(int n, int total_weight, int weight[], int value[])
{
    if (n == 0 || total_weight == 0)
        return 0;

    if (dp[n][total_weight] != -1)
    {
        return dp[n][total_weight];
    }

    if (weight[n - 1] <= total_weight)
    {
        int op1 = knapsack(n - 1, total_weight - weight[n - 1], weight, value) + value[n - 1];
        int op2 = knapsack(n - 1, total_weight, weight, value);
        return dp[n][total_weight] = max(op1, op2);
    }

    else
    {
        return dp[n][total_weight] = knapsack(n - 1, total_weight, weight, value);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, total_weight;
        cin >> n >> total_weight;

        int weight[n], value[n];

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= total_weight; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << knapsack(n, total_weight, weight, value) << endl;
    }
    return 0;
}