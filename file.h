#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "graph.h"

using namespace std;

class FileReader {
public:
    // Reads node data from file and adds it to the graph
    static void readFromFile(Graph& graph, const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open the file!" << endl;
            return;
        }

        graph.addNode(0, 0, 0);  // Ensure at least one starting node

        string line;
        while (getline(file, line)) {
            string label;
            int x, y, z;
            char ch;

            stringstream ss(line);
            if (ss >> label >> ch >> x >> ch >> y >> ch >> z) {
                graph.addNode(x, y, z);
            } else {
                cerr << "Error: Failed to parse line: " << line << endl;
            }
        }
    }

    // Exports graph data to a file
    static void exportGraphData(const Graph& graph) {
        ofstream file("graph_data.txt");
        if (!file) {
            cerr << "Error: Unable to create graph_data.txt" << endl;
            return;
        }

        // Save nodes
        file << "Nodes\n";
        for (size_t i = 0; i < graph.nodes.size(); ++i) {
            file << i << " " << graph.nodes[i]->x << " " << graph.nodes[i]->y << " " << graph.nodes[i]->z << "\n";
        }

        // Save edges
        file << "Edges\n";
        for (const auto& pair : graph.adjList) {
            int u = pair.first;
            for (const auto& edge : pair.second) {
                int v = edge.first;
                file << u << " " << v << "\n";
            }
        }
        file.close();
        cout << "Graph data exported to graph_data.txt" << endl;
    }
};

#endif
