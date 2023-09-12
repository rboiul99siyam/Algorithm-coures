#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n], total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        total_sum += ar[i];
    }

    bool dp[n + 1][total_sum + 1];

    dp[0][0] = true;
    for (int i = 1; i <= total_sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= total_sum; j++)
        {
            if (ar[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - ar[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total_sum; j++)
        {
            if (ar[i - 1] <= j)
            {
                v.push_back(j);
            }
        }
    }
    int ans = INT_MAX;
    for (int val : v)
    {
        int s1 = val;
        int s2 = total_sum - s1;

        ans = min(ans, abs(s1 - s2));
    }

    cout << ans;
    return 0;
}

/*
4
1 5 4 11
 */