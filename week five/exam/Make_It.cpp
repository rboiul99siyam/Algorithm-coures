#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];

int solve(int crntvalue, int n)
{
    if (crntvalue == n)
    {
        return 1;
    }

    if (crntvalue > n)
    {
        return 0;
    }

    if (dp[crntvalue] != -1)
    {
        return dp[crntvalue];
    }

    int op1 = solve(crntvalue + 3, n);
    int op2 = solve(crntvalue * 2, n);

    if (n % 2 == 0)
    {
        op2 = solve(crntvalue * 2, n);
    }
    else
    {
        op1 = solve(crntvalue + 3, n);
    }

    return dp[crntvalue] = op1 || op2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            dp[i] = -1;
        }
        if (solve(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
