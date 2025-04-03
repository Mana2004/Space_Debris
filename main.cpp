#include "file.h"
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph graph;

    FileReader::readFromFile(graph, "input.txt");

    if (graph.nodes.empty()) {
        cerr << "Error: No nodes were added to the graph!" << endl;
        return 1;
    }

    graph.createEdges();

    graph.printAdjacencyList();

    graph.blindTraversal(0);

    FileReader::exportGraphData(graph);

    return 0;
}

