#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int parentsize[N];

void dus_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentsize[i] = 1;
    }
}
int dus_find(int child)
{
    while (parent[child] != -1)
    {
        child = parent[child];
    }
    return child;
}

void dus_union(int a, int b)
{
    int leaderA = dus_find(a);
    int leaderB = dus_find(b);

    if (leaderA != leaderB)
    {
        if (parentsize[leaderA] > parentsize[leaderB])
        {
            parentsize[leaderB] = leaderA;
            parentsize[leaderA] += parentsize[leaderB];
        }
        else
        {
            parentsize[leaderA] = leaderB;
            parentsize[leaderB] += parentsize[leaderA];
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    dus_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dus_union(a, b);
    }

    cout<< dus_find(4);
    return 0;
}

/*

sample input :
7
4
1 2
2 3
4 5
6 5

 */
