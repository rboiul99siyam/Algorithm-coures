#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int dp[N][N];
int main()
{
    int n,sum;
    cin >> n >>sum;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    // int sum;
    // cin >> sum;

    dp[0][0] = true;

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (ar[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - ar[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "count a subset : " << dp[n][sum] << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/* 
sample input : 
4
1 3 4 6
7

 */