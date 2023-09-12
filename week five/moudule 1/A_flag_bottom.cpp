#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];
int main()
{
    int n;
    cin >> n;
    int ar[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    dp[1] = 0;
    dp[2] = abs(ar[2] - ar[1]);

    for (int i = 3; i <= n; i++)
    {
        int choice1 = dp[i - 1] + abs(ar[i] - ar[i - 1]);
        int choice2 = dp[i - 2] + abs(ar[i] - ar[i - 2]);
        dp[i] = min(choice1, choice2);
    }

    cout << dp[n];

    return 0;
}