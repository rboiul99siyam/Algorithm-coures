#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            
        }
    }

    // Apply Floyd-Warshall algorithm to find shortest distances
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // Find maximum shortest distance
    int maxShortestDistance = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxShortestDistance = max(maxShortestDistance, graph[i][j]);
        }
    }

    cout << maxShortestDistance << endl;

    return 0;
}
