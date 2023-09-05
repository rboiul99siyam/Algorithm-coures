#include <bits/stdc++.h>
using namespace std;

// ----------- const value declar korlam -------------->
typedef pair<int, int> pi;
const int N = 1e5 + 10;
vector<pi> p[N];
bool vis[N];

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s, int n)

{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgelist;
    pq.push(Edge(s, s, 0));

    int cnt = 0;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();

        int u = parent.a;
        int v = parent.b;
        int w = parent.w;

        if (vis[v])
            continue;
        vis[v] = true;
        cnt++;
        edgelist.push_back(parent);

        for (auto child : p[v])
        {
            int vartex = child.first;
            int edgecost = child.second;

            pq.push(Edge(v, vartex, edgecost));
        }
    }
    edgelist.erase(edgelist.begin());

    long long result = 0;
    for (Edge v : edgelist)
    {
        result += (long long)(v.w);
    }

    if (cnt == n)
    {
        cout << result << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        p[a].push_back({b, w});
        p[b].push_back({a, w});
    }

    prims(1, n);
    return 0;
}

/*
sample input :

5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4


 */