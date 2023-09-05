// #include <bits/stdc++.h>
// using namespace std;

// // global value dicliar korlam
// typedef pair<int, int> pii;
// const int N = 1e3 + 10;
// int visited[N][N];
// int level[N][N];
// pii parent[N][N];
// vector<pii> distination = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// vector<string> g;
// int n, m;

// // valid check
// bool isValid(int i, int j)
// {
//     return (i >= 0 && i < n && j >= 0 && j < m);
// }

// // function dicliar karlam

// void bfs(int si, int sj)
// {
//     queue<pii> q;
//     q.push({si, sj});
//     visited[si][sj] = true;
//     level[si][sj] = 0;

//     while (!q.empty())
//     {
//         pii sN = q.front();

//         int i = sN.first;
//         int j = sN.second;

//         q.pop();

//         for (auto d : distination)
//         {
//             int ni = i + d.first;
//             int nj = j + d.second;

//             if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'X')
//             {
//                 q.push({ni, nj});
//                 visited[ni][nj] = true;
//                 level[ni][nj] = level[i][j] + 1;
//                 parent[ni][nj] = {i, j};
//             }
//         }
//     }
// }
// int main()
// {

//     cin >> n >> m;

//     int si, sj, di, dj;
//     for (int i = 0; i < n; i++)
//     {
//         string x;
//         cin >> x;
//         for (int j = 0; j < m; j++)
//         {
//             if (x[j] == 's')
//                 si = i, sj = j;
//             if (x[j] = 'e')
//                 di = i, dj = j;
//         }
//         g.push_back(x);
//     }

//     bfs(si, sj);
//     if (level[di][dj] != 0)
//     {
//         cout << level[di][dj] << " ";
//     }
//     else
//     {
//         cout << "-1" << endl;
//         return 0;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

//-------------------galbally value declar korlam --------------->

typedef pair<int, int> pii;
const int N = 1e3 + 10;
int visited[N][N];
int level[N][N];
vector<string> g;
vector<pii> dist = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pii parent[N][N];
int row, cul;

// -------------- isVaild check koren ------------------>

bool isVaild(int i, int j)
{
    return (i >= 0 && i < row && j >= 0 && j < cul);
}

//------------function declar korlam --------------->

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii f = q.front();
        q.pop();

        int i = f.first;
        int j = f.second;

        for (auto d : dist)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isVaild(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

main()
{

    cin >> row >> cul;

    int si, sj, di, dj;
    for (int i = 0; i < row; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < cul; j++)
        {
            if (x[j] == 's')
                si = i, sj = j;

            if (x[j] == 'e')
                di = i, dj = j;
        }

        g.push_back(x);
    }

    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
       cout<<"NO"<<endl;
    //    return 0;
    }

    return 0;
}