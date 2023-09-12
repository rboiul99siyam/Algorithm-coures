#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int dp[N][N];

int subset_count(int n, int ar[], int sum)
{
    // base case
    if (n == 0)
    {
        if (sum == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (ar[n - 1] <= sum)
    {
        int op1 = subset_count(n - 1, ar, sum - ar[n - 1]);
        int op2 = subset_count(n - 1, ar, sum);

        return dp[n][sum] = op1 + op2;
    }
    else
    {
        return dp[n][sum] = subset_count(n - 1, ar, sum);
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

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "count subset : " << subset_count(n, ar, sum);

    return 0;
}
/*
sample input:

4
1 2 3 6
7
*/