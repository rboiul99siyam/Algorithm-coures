// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;
// int dist[N];
// vector<pair<int, int>> g[N];

// void bellman(int s, int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         dist[i] = INF;
//     }

//     dist[s] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int u = 1; u <= n; u++)
//         {
//             for (auto child : g[u])
//             {
//                 int vartex = child.first;
//                 int edcost = child.second;

//                 if (dist[u] != INF && dist[vartex] > dist[u] + edcost)
//                 {
//                     dist[vartex] = dist[u] + edcost;
//                 }
//             }
//         }
//     }
// }

// int main()
// {

//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         g[a].push_back({b, w});
//     }

//     int s;
//     cin >> s;
//     int q;
//     cin >> q;

//     bellman(s,n);
//     while (q--)
//     {
//         int d;
//         cin >> d;
//         if (dist[d] == INF)
//         {
//             cout << "Not Possible" << endl;
//         }
//         else

//         {
//             cout << dist[d] << endl;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

class Edge
{
public:
    int a;
    int b;
    int w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int main()
{

    int n, e;
    cin >> n >> e;

    vector<Edge> v;
    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    int s, d;
    cin >> s;
    int dist[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {

        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.a;
            int b = ed.b;
            int w = ed.w;

            if (dist[a] != INF && dist[b] > dist[a] + w)
            {
                dist[b] = dist[a] + w;
            }
        }
    }

    bool cd = false;

    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        int a = ed.a;
        int b = ed.b;
        int w = ed.w;

        if (dist[a] != INF && dist[b] > dist[a] + w)
        {
            cd = true;
            break;
            dist[b] = dist[a] + w;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        cin >> d;

        if (cd)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (dist[d] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dist[d] << endl;
        }
    }

    return 0;
}
