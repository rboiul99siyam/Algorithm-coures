// 1. find korte hobe //2.set call korte hobe
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];

// sobai ke parent kore dilam
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }
}

// parent check korlam
int dsu_find(int n)
{
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}

// sobai parent kore dilam

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        parent[leaderB] = leaderA;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    return 0;
}