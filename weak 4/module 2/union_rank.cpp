#include <bits/stdc++.h>
using namespace std;

//-------- const value declar korlam ----------->
const int N = 1e4 + 10;
int parent[N];
int parentlevel[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentlevel[i] = 0;
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

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentlevel[leaderA] > parentlevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentlevel[leaderB] > parentlevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentlevel[leaderA]++;
        }
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

    cout << dsu_find(4);

    return 0;
}

/*
sample input:
7
4
1 2
2 3
4 5
6 5

 */