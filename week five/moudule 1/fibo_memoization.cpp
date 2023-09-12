// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const int N = 1e5 + 10;
// ll save[N];

// ll fibo(ll n)
// {
//     // base

//     if (n == 0 || n == 1)
//         return 1;

//     // memoization

//     if (save[n] != -1)
//     {
//         return save[n];
//     }

//     ll ans1 = fibo(n - 1);
//     ll ans2 = fibo(n - 2);

//     save[n] = ans1 + ans2;
//     return save[n];
// }

// int main()
// {
//     ll n;
//     cin >> n;

//     for (int i = 0; i <= n; i++)
//     {
//         save[i] = -1;
//     }

//     cout << fibo(n) << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int save[N];
int fibo_memoization(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (save[n] != -1)
    {
        return save[n];
    }
    int ans1 = fibo_memoization(n - 1);
    int ans2 = fibo_memoization(n - 2);
    save[n] = ans1 + ans2;
    return save[n];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        save[i] = -1;
    }
    cout << fibo_memoization(n);

    return 0;
}