#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int dp[N][N];

bool subset(int n, int ar[], int sum)
{
    // base case
    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (ar[n - 1] <= sum)
    {
        bool op1 = subset(n - 1, ar, sum - ar[n - 1]);
        bool op2 = subset(n - 1, ar, sum);

        return dp[n][sum] = op1 || op2;
    }
    else
    {
        return dp[n][sum] = subset(n, ar, sum - ar[n - 1]);
    }
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    int sum;
    cin >> sum;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }

    if (subset(n, ar, sum))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
/*
sample input :
4
1 2 4 6
7
 */