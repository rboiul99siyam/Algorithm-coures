// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// int visited[N][N];
// vector<string> g;

// bool isVaild(int i, int j, int n, int m)
// {
//     if (i >= 0 && i < n && j >= 0 && j < m)
//         ;
// }
// void dfs(int i, int j)
// {
//     if (!isVaild)
//         return;
//     if (visited[i][j] == true)
//         return;
//     if (g[i][j] == '#')
//         return;
//     visited[i][j] = true;
//     dfs(i, j - 1);
//     dfs(i, j + 1);
//     dfs(i - 1, j);
//     dfs(i + 1, j);
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         string x;
//         cin >> x;
//         g.push_back(x);
//     }

//     int room = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (g[i][j] == '#')
//                 continue;
//             if (visited[i][j] == true)
//                 continue;
//             dfs(i, j);
//             room++;
//         }
//     }

//     cout << "couter room " << room;
//     return 0;
// }

/*
########
#..#...#
#..#.#.#
#..#...#
########

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
bool visited[N][N];
vector<string> g;

bool isVaild(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j)
{

    if (!isVaild)
        return;
    if (visited[i][j])
        return;
    if (g[i][j] == '#')
        return;
    visited[i][j] = true;
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i - 1, j);
    dfs(i + 1, j);
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        g.push_back(x);
    }

    int room = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if (g[i][j] == '#')
                continue;
            if (visited[i][j] == true)
                continue;

            dfs(i, j);
            room++;
        }
    }
    cout<<room<<endl;
    return 0;
}
