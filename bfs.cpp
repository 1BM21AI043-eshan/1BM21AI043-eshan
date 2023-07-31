#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    cout << "BFS traversal starting from node 0: ";
    bfs(graph, 0);
    cout << endl;

    return 0;
}
