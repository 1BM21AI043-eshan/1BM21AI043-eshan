#include <iostream>
#include <vector>
#include <algorithm>


struct Edge {
    int src, dest, weight;
};


struct DisjointSet {
    int parent;
    int rank;
};


int find(std::vector<DisjointSet>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(std::vector<DisjointSet>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}


void KruskalMST(std::vector<Edge>& edges, int V) {
    std::vector<Edge> mst;
    std::vector<DisjointSet> subsets(V);


    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }


    std::sort(edges.begin(), edges.end(), compareEdges);


    for (const auto& edge : edges) {
        int srcRoot = find(subsets, edge.src);
        int destRoot = find(subsets, edge.dest);


        if (srcRoot != destRoot) {
            mst.push_back(edge);
            Union(subsets, srcRoot, destRoot);
        }
    }


    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : mst)
        std::cout << edge.src << " -- " << edge.dest << " : " << edge.weight << std::endl;
}

int main() {
    int V, E;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    std::cout << "Enter the number of edges: ";
    std::cin >> E;

    std::vector<Edge> edges(E);

    std::cout << "Enter the source, destination, and weight of each edge:" << std::endl;
    for (int i = 0; i < E; ++i)
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    KruskalMST(edges, V);

    return 0;
}
