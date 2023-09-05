#include <bits/stdc++.h>
using namespace std;

//-------------- const value declar korlam --------------->
const int N = 1e5 + 10;
vector<int> g[N];
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (auto l : g[i])
        {
            cout << l << " " ;
        }
        cout<<endl;
    }
    return 0;
}

/*
 4 4
1 2
1 3
1 4
4 3 */