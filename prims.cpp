#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;


class Graph
{
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    vector<pii> primMST();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

vector<pii> Graph::primMST() {

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int src = 0;


    vector<int> key(V, INT_MAX);


    vector<int> parent(V, -1);


    vector<bool> inMST(V, false);


    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;


        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;


            if (!inMST[v] && weight < key[v]) {

                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }


    vector<pii> mst;
    for (int i = 1; i < V; ++i) {
        mst.push_back(make_pair(parent[i], i));
    }

    return mst;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    vector<pii> mst = graph.primMST();

    cout << "Minimum Spanning Tree:\n";
    for (auto& edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
