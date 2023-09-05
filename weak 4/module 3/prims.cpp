#include <bits/stdc++.h>
using namespace std;

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
            int cost = child.second;

            if (!vis[vartex])
            {
                pq.push(Edge(v, vartex, cost));
            }
        }
    }

    edgelist.erase(edgelist.begin());
    cout << " --------- Robiul islam ------------ " << endl;
    for (Edge v : edgelist)
    {
        cout << v.a << " " << v.b << " " << v.w << endl;
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
    prims(1);
    return 0;
}

/*
sample input :

8
11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
3 4 11
4 8 9
4 7 11
7 6 1
8 6 2
//  */
