#include <bits/stdc++.h>
using namespace std;


void solve(int ar1[], int ar2[], int n, int x, int ans[])
{
    int a = 0, b = 0, k = 0;
    while (a < n && b < x)
    {
        if (ar1[a] > ar2[b])
        {
            ans[k++] = ar1[a++];
        }
        else
        {
            ans[k++] = ar2[b++];
        }
    }
    while (a < n)
    {
        ans[k++] = ar1[a++];
    }
    while (b < x)
    {
        ans[k++] = ar2[b++];
    }
}
int main()
{
    int n;
    cin >> n;
    int ar1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar1[i];
    }

    int x;
    cin >> x;
    int ar2[x];
    for (int i = 0; i < x; i++)
    {
        cin >> ar2[i];
    }
    int ans[n + x];
    solve(ar1, ar2, n, x, ans);
    for (int i = 0; i < n + x; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}