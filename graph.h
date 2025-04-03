#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

class Graph {
public:
    struct Node {
        int x, y, z;
        Node(int x, int y, int z) : x(x), y(y), z(z) {}
    };

    vector<Node*> nodes;
    unordered_map<int, vector<pair<int, double>>> adjList; // Adjacency list

    // Adds a new node and prints its coordinates.
    void addNode(int x, int y, int z) {
        nodes.push_back(new Node(x, y, z));
        cout << "Added Node: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    // Computes the Euclidean distance between two nodes.
    double distance(Node* a, Node* b) {
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
    }

    // Connects every node to every other node (complete graph).
    void createEdges() {
        for (size_t i = 0; i < nodes.size(); ++i) {
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                double dist = distance(nodes[i], nodes[j]);
                adjList[i].emplace_back(j, dist);
                adjList[j].emplace_back(i, dist);
            }
        }
    }
    
    // Utility function to print the adjacency list.
    void printAdjacencyList() {
        cout << "\nAdjacency List:\n";
        for (const auto& pair : adjList) {
            cout << "Node " << pair.first << " -> ";
            for (const auto& edge : pair.second) {
                cout << "(Node " << edge.first << ", Distance: " << edge.second << ") ";
            }
            cout << endl;
        }
    }
    
    // Blind Traversal using a greedy nearest neighbor approach.
    // Once a node is visited, it is no longer considered.
    vector<int> blindTraversal(int startIdx) {
        int n = nodes.size();
        vector<bool> visited(n, false);
        vector<int> path;
        double totalCost = 0.0;

        int current = startIdx;
        path.push_back(current);
        visited[current] = true;

        // Continue until all nodes are visited.
        while (path.size() < n) {
            double minCost = numeric_limits<double>::infinity();
            int nextNode = -1;

            // Consider every neighbor from the current node.
            for (auto &edge : adjList[current]) {
                int neighbor = edge.first;
                double cost = edge.second;
                // Only consider unvisited nodes.
                if (!visited[neighbor] && cost < minCost) {
                    minCost = cost;
                    nextNode = neighbor;
                }
            }

            if (nextNode == -1) {
                // In a complete graph this should not happen.
                break;
            }

            visited[nextNode] = true;
            path.push_back(nextNode);
            totalCost += minCost;
            current = nextNode;
        }

        // Print the traversal results.
        cout << "\nBlind Traversal (Avoiding revisits): ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1)
                cout << " -> ";
        }
        cout << "\nTotal Traversal Cost: " << totalCost << endl;

        return path;
    }
};

#endif