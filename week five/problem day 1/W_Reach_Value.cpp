#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(ll crnt, ll N)
{
    if (crnt == N)
    {
        return true;
    }

    if (crnt > N)
    {
        return false;
    }

    return solve(crnt * 10, N) || solve(crnt * 20, N);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll N;
        cin >> N;

        if(solve(1,N))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}