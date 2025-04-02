#include "graph.h"
#include "file.h"

int main() {
    Graph graph;
    FileReader::readFromFile(graph, "input.txt");
    graph.createEdges();

    int startIdx = 0; // Start from the first node
    vector<int> shortestPathTree = graph.dijkstra(startIdx);

    cout << "\nShortest path tree using Dijkstra's Algorithm:" << endl;
    for (size_t i = 0; i < shortestPathTree.size(); ++i) {
        if (shortestPathTree[i] != -1)
            cout << "Node " << i << " <- " << shortestPathTree[i] << endl;
    }

    return 0;
}