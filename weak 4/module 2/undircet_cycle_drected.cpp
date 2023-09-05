#include <bits/stdc++.h>
using namespace std;

//-------------------- const value declar korlam  ------------>
const int N = 1e4 + 10;
int parent[N];
int parentLevel[N];

//---------------- void check korlam --------------->
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

// ---------- parnet find korlam -------------->
int dsu_find(int child)
{

    while (parent[child] != -1)
    {
        child = parent[child];
    }
    return child;
}

//------------ data structure union ------------->

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
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
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
        {
            cout << "undirceted cycle drected in bewteen : " << a << " " << b << endl;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    cout << dsu_find(4);
    return 0;
}

/*
 sample input :
5
5
1 2
2 5
1 4
2 3
4 5
 */