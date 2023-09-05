// #include <bits/stdc++.h>
// using namespace std;

// // ----------------const and globally vulue declar korlam --------->
// typedef pair<int, int> pii;
// const int N = 1e3 + 10;
// vector<string> g;
// int level[N][N];
// int visited[N][N];
// pii parent[N][N];
// vector<pii> dist = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// int r, c;

// // ----------- isValid cheak korlam ------------>
// bool isValid(int i, int j)
// {
//     return (i >= 0 && i < r && j >= 0 && j < c);
// }
// //------------function declar korlam ------------->
// void bfs(int si, int sj)
// {
//     queue<pii> q;
//     q.push({si, sj});
//     visited[si][sj] = true;
//     level[si][sj] = 0;

//     while (!q.empty())
//     {
//         pii f = q.front();
//         q.pop();

//         int i = f.first;
//         int j = f.second;

//         for (auto d : dist)
//         {
//             int n_ri = i + d.first;
//             int n_cl = j + d.second;

//             if (isValid(n_ri, n_cl) && !visited[n_ri][n_cl] && g[n_ri][n_cl] != 'x')
//             {
//                 q.push({n_ri, n_cl});
//                 visited[n_ri][n_cl] = true;
//                 level[n_ri][n_cl] = level[i][j] + 1;
//                 parent[n_ri][n_cl] = {i, j};
//             }
//         }
//     }
// }
// int main()
// {

//     cin >> r >> c;

//     int si, sj, di, dj;
//     for (int i = 0; i < r; i++)
//     {
//         string x;
//         cin >> x;
//         for (int j = 0; j < c; j++)
//         {
//             if (x[j] == 's')
//                 si = i, sj = j;
//             if (x[j] == 'e')
//                 di = i, dj = j;
//         }
//         g.push_back(x);
//     }

//     bfs(si, sj);
//     cout << "->" << level[di][dj] << endl;

//     vector<pii> path;
//     pii curnt = {di, dj};

//     while (curnt.first != 0 && curnt.second != 0)
//     {
//         path.push_back(curnt);
//         curnt = parent[curnt.first][curnt.second];
//     }

//     path.push_back({si, sj});

//     reverse(path.begin(), path.end());

//     for (int i = 1; i < path.size(); i++)
//     {
//         if (path[i - 1].first == path[i].first) // left right
//         {
//             if (path[i - 1].second == path[i].second - 1) // right // left
//             {
//                 cout << "R";
//             }
//             else
//             {
//                 cout << "L";
//             }
//         }
//         else
//         {
//             if (path[i - 1].first == path[i].first - 1)
//             {
//                 cout << "D";
//             }
//             else
//             {
//                 cout << "U";
//             }
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// const value and glubally declar korlam

typedef pair<int, int> pii;
const int N = 1e3 + 10;
int visited[N][N];
int level[N][N];
vector<string> g;
int n, m;
pii parent[N][N];
vector<pii> distanation = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// vaild check korlam

bool isvaild(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// function declar korlam

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

        for (auto d : distanation)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isvaild(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x')
            {

                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;

                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
                si = i, sj = j;
            if (x[j] == 'e')
                di = i, dj = j;
        }
        g.push_back(x);
    }

    bfs(si, sj);
    cout << level[di][dj] <<endl;

    // shortest path

    vector<pii> path;
    pii crnt = {di, dj};

    while (crnt.first != 0 && crnt.second != 0)
    {
        path.push_back(crnt);
        crnt = parent[crnt.first][crnt.second];
    }

    path.push_back({si, sj});
    reverse(path.begin(), path.end());

    for (int i = 1; i < path.size(); i++)
    {

        if (path[i - 1].first == path[i].first) // left right joyar jonno use kore 
        {

            if (path[i - 1].second == path[i].second - 1)// right jabe eta 
            {
                cout<<"R";
            }
            else
            {
                cout<<"L";
            }
        }

        else
        {
            if(path[i -1].first == path[i].first-1)
            {
                cout<<"D";
            }
            else
            {
                cout<<"U";
            }
        }
    }

    return 0;
}
