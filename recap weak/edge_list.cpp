#include <bits/stdc++.h>
using namespace std;

//------------ cosnt value declar -------------------->
const int N = 1e5 + 10;
vector<pair<int, int>> g;
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Node " << g[i].first << " theke " << g[i].second << " cenection " << endl;
    }
    return 0;
}

/*
 4 4
 1 2
 1 3
 1 4
 4 3

*/