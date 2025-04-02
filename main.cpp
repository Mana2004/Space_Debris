#include "graph.h"
#include "file.h"

int main() {
    Graph graph;

    FileReader::readFromFile(graph, "input.txt");

    if (graph.nodes.empty()) {
        cerr << "Error: No nodes were added to the graph!" << endl;
        return 1;
    }

    cout << "\nNodes in the graph:" << endl;
    for (size_t i = 0; i < graph.nodes.size(); ++i) {
        cout << "Node " << i << ": (" 
             << graph.nodes[i]->x << ", " 
             << graph.nodes[i]->y << ", " 
             << graph.nodes[i]->z << ")" << endl;
    }

    graph.createEdges();

    if (graph.adjList.empty()) {
        cerr << "Error: No edges were created! Ensure the input file has enough valid nodes." << endl;
        return 1;
    }

    int startIdx = 0;  // Define the start index
    vector<int> shortestPathTree = graph.dijkstra(startIdx);

    cout << "\nShortest Path Tree using Dijkstra's Algorithm:\n";
    for (size_t i = 0; i < shortestPathTree.size(); ++i) {
        if (i != startIdx && shortestPathTree[i] != -1) {
            cout << "Node " << i << " <- " << shortestPathTree[i] << endl;
        }
    }

    return 0;
}
