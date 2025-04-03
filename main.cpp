#include "file.h"
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph graph;
    
    // Read nodes from the file. Ensure that "input.txt" has valid node definitions.
    FileReader::readFromFile(graph, "input.txt");

    if (graph.nodes.empty()) {
        cerr << "Error: No nodes were added to the graph!" << endl;
        return 1;
    }

    // Create a complete graph (each node is connected to every other).
    graph.createEdges();

    // Print the adjacency list for verification.
    graph.printAdjacencyList();

    // Perform the blind traversal starting from node 0.
    graph.blindTraversal(0);

    return 0;
}
