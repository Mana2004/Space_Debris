#include "file.h"
#include "graph.h"

int main() {
    Graph graph;

    FileReader::readFromFile(graph, "input.txt");

    if (graph.nodes.empty()) {
        cerr << "Error: No nodes were added to the graph!" << endl;
        return 1;
    }

    graph.createEdges();

    vector<int> shortestPathTree = graph.dijkstra(0);

    cout << "Shortest Path Tree using Dijkstra's Algorithm:\n";
    for (size_t i = 0; i < shortestPathTree.size(); ++i) {
        if (shortestPathTree[i] != -1) {
            cout << "Node " << i << " <- " << shortestPathTree[i] << endl;
        } else {
            cout << "Node " << i << " is unreachable from Node 0" << endl;
        }
    }

    return 0;
}
