#include <bits/stdc++.h>
using namespace std;

int solve(int n, int ar[], int target, int idx, int crntSum)
{
    // base case
    if (idx == n)
    {
        return target == crntSum;
    }

    int op1 = solve(n, ar, target, idx + 1, crntSum + ar[idx]);
    int op2 = solve(n, ar, target, idx + 1, crntSum - ar[idx]);
    return op1 + op2;
}
int main()
{
    int n, target;
    cin >> n >> target;

    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    if (solve(n, ar, target, 0, 0))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
        return 0;
}