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

    int startIndex = 0;
    vector<int> shortestPathTree = graph.ucs(startIndex);

    cout << "Shortest Path Tree using UCS Algorithm:\n";
    for (size_t i = 0; i < shortestPathTree.size(); ++i) {
        if (i == startIndex) {
            cout << "Node " << i << " is the starting node" << endl;
        } else if (shortestPathTree[i] != -1) {
            cout << "Node " << i << " <- " << shortestPathTree[i] << endl;
        } else {
            cout << "Node " << i << " is unreachable from Node " << startIndex << endl;
        }
    }

    return 0;
}
