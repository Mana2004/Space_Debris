#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <limits>
#include <iostream>
#include <time.h>

using namespace std;

class Graph {
public:
    struct Node {
        int x, y, z;
        Node(int x, int y, int z) : x(x), y(y), z(z) {}
    };

    vector<Node*> nodes;
    unordered_map<int, vector<pair<int, double>>> adjList;
    vector<pair<int, int>> traversalPath;

    void addNode(int x, int y, int z) {
        nodes.push_back(new Node(x, y, z));
        cout << "Added Node: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    double distance(Node* a, Node* b) {
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
    }

    void createEdges() {
        for (size_t i = 0; i < nodes.size(); ++i) {
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                double dist = distance(nodes[i], nodes[j]);
                adjList[i].emplace_back(j, dist);
                adjList[j].emplace_back(i, dist);
            }
        }
    }
    
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
    
    vector<int> blindTraversal(int startIdx) {
        clock_t start_time = clock();
    
        int n = nodes.size();
        vector<bool> visited(n, false);
        vector<int> path;
        double totalCost = 0.0;
    
        traversalPath.clear();
    
        int current = startIdx;
        path.push_back(current);
        visited[current] = true;
    
        while (path.size() < n) {
            double minCost = numeric_limits<double>::infinity();
            int nextNode = -1;
    
            for (auto &edge : adjList[current]) {
                int neighbor = edge.first;
                double cost = edge.second;
                if (!visited[neighbor] && cost < minCost) {
                    minCost = cost;
                    nextNode = neighbor;
                }
            }
    
            if (nextNode == -1) {
                break;
            }
    
            visited[nextNode] = true;
            traversalPath.emplace_back(current, nextNode);
            path.push_back(nextNode);
            totalCost += minCost;
            current = nextNode;
        }
    
        clock_t end_time = clock();
        double duration = double(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    
        cout << "\nBlind Traversal : ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1)
                cout << " -> ";
        }
        cout << "\nTotal Traversal Cost: " << totalCost << endl;
        cout << "Time: " << duration << " ms" << endl;
    
        return path;
    }
    
};

#endif