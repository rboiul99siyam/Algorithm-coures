#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
const int N = 1e5 + 10;
bool vis[N];
vector<pi> p[N];

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

void prims(int s)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgelist;
    pq.push(Edge(s, s, 0));

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
        edgelist.push_back(parent);

        for (auto child : p[v])
        {
            int vartex = child.first;
            int edgecost = child.second;

            pq.push(Edge(v, vartex, edgecost));
        }
    }

    int sum = 0;
    edgelist.erase(edgelist.begin());
    for (Edge v : edgelist)
    {
        sum += (v.w);
    }
    cout << sum;
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

    prims(1);
    return 0;
}