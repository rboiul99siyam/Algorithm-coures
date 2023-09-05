#include <bits/stdc++.h>
using namespace std;

// ---------- const value declar korlam -------------->
const int N = 1e5 + 10;
int parent[N];
int parentsize[N];
int mx = 0;

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentsize[i] = 1;
    }
}

int dsu_find(int child)
{
    while (parent[child] != -1)
    {
        child = parent[child];
    }

    return child;
}

void dsu_union_size(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentsize[leaderA] > parentsize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentsize[leaderA] += parentsize[leaderB];
            mx = max(mx, parentsize[leaderA]);
        }
        else
        {
            parent[leaderA] = leaderB;
            parentsize[leaderB] += parentsize[leaderA];
            mx = max(mx, parentsize[leaderB]);
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    dsu_set(n);
    int cmp = n;
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA != leaderB)
        {
            cmp--;
            dsu_union_size(a, b);
            cout << cmp << " " << mx << endl;
        }
    }

    return 0;
}