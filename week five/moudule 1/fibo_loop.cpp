// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main()
// {
//     ll n;
//     cin >> n;
//     ll ar[n + 1];
//     ar[0] = 1;
//     ar[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         ar[i] = ar[i - 1] + ar[i - 2];
//     }

//     cout << ar[n] << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n + 1];
    ar[0] = 1;
    ar[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        ar[i] = ar[i - 1] + ar[i - 2];
    }
    cout<<ar[n];

    return 0;
}