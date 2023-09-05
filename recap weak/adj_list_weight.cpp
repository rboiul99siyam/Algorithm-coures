#include <bits/stdc++.h>
using namespace std;

// --------------------- const value declar korlam ---------------->
const int N = 1e5 + 10;
vector<pair<int, int>> g[N]; // -------- pair neoyar karon  holo  nodes weight koto ta dekar jonno
int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " ";
        for (auto l : g[i])
        {
            cout << "( Nodes " << l.first << " : "
                 << "  weighted  " << l.second << " ) ";
        }
        cout<<endl;
    }
    return 0;
}
/*
4 4
1 2 10
1 3 9
1 4 11
4 3 12
*/