#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    cout << node << " ";
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int main() {
    int numNodes = 7;
    vector<vector<int>> graph(numNodes);

    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 4};
    graph[3] = {1, 5};
    graph[4] = {2, 5};
    graph[5] = {3, 4, 6};
    graph[6] = {5};

    vector<bool> visited(numNodes, false);

    cout << "DFS traversal starting from node 0: ";
    dfs(graph, visited, 0);
    cout << endl;

    return 0;
}
