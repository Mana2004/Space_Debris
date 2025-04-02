#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>
#include <cmath>

using namespace std;

class Graph {
public:
    struct Node {
        int x, y, z;
        Node(int c1, int c2, int c3) : x(c1), y(c2), z(c3) {}
    };

    vector<Node*> nodes;
    unordered_map<int, vector<pair<int, double>>> adjList;
    bool matrix[10][10][10] = {false};

    void addNode(int x, int y, int z) {
        if (x >= 0 && x < 10 && y >= 0 && y < 10 && z >= 0 && z < 10 && !matrix[x][y][z]) {
            nodes.push_back(new Node(x, y, z));
            matrix[x][y][z] = true;
            cout << "Added Node " << nodes.size() - 1 << ": (" << x << ", " << y << ", " << z << ")" << endl;
        } else {
            cout << "Failed to add Node: (" << x << ", " << y << ", " << z << ") - Already exists or out of bounds." << endl;
        }
    }     

    void addEdge(int idx1, int idx2) {
        if (idx1 < 0 || idx2 < 0 || idx1 >= static_cast<int>(nodes.size()) || idx2 >= static_cast<int>(nodes.size()) || idx1 == idx2) {
            cout << "Invalid edge (" << idx1 << ", " << idx2 << ")" << endl;
            return;
        }
        double weight = distance(nodes[idx1], nodes[idx2]);
        adjList[idx1].emplace_back(idx2, weight);
        adjList[idx2].emplace_back(idx1, weight);
    }    

    double distance(Node* a, Node* b) {
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
    }

    void createEdges() {
        if (nodes.size() < 2) {
            cout << "Not enough nodes to create edges!" << endl;
            return;
        }

        cout << "\nCreating edges...\n";
        for (size_t i = 0; i < nodes.size(); ++i) {
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                addEdge(i, j);
            }
        }

        cout << "\nAdjacency List:\n";
        for (const auto& [key, value] : adjList) {
            cout << "Node " << key << " -> ";
            for (const auto& [neighbor, weight] : value) {
                cout << "(Node " << neighbor << ", Weight " << weight << ") ";
            }
            cout << endl;
        }
    }

    vector<int> dijkstra(int startIdx) {
        if (nodes.empty()) {
            cout << "Error: No nodes in the graph!" << endl;
            return {};
        }
        if (startIdx < 0 || startIdx >= static_cast<int>(nodes.size())) {
            cout << "Error: Invalid start index!" << endl;
            return {};
        }
    
        vector<bool> visited(nodes.size(), false);
        vector<int> shortestPath;
        
        int current = startIdx;
        visited[current] = true;
        shortestPath.push_back(current);
    
        cout << "\nStarting Dijkstra from Node " << current << endl;
    
        while (shortestPath.size() < nodes.size()) {
            int nextNode = -1;
            double minDist = numeric_limits<double>::infinity();
    
            for (const auto& [neighbor, weight] : adjList[current]) {
                if (!visited[neighbor] && weight < minDist) {
                    minDist = weight;
                    nextNode = neighbor;
                }
            }
    
            if (nextNode == -1) {
                cout << "Error: Graph might not be fully connected!" << endl;
                break;
            }
    
            visited[nextNode] = true;
            shortestPath.push_back(nextNode);
            cout << "Moving to Node " << nextNode << " with weight " << minDist << endl;
    
            current = nextNode;
        }
    
        cout << "\nFinal Shortest Path Order:\n";
        for (int node : shortestPath) {
            cout << "Node " << node << " -> ";
        }
        cout << "End\n";
    
        return shortestPath;
    }              

};

#endif
