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

    vector<Node*> nodes; // List of all nodes
    unordered_map<int, vector<pair<int, double>>> adjList; // Adjacency list with weights
    bool matrix[10][10][10] = {false}; // 3D space matrix

    void addNode(int x, int y, int z) {
        if (x >= 0 && x < 10 && y >= 0 && y < 10 && z >= 0 && z < 10 && !matrix[x][y][z]) {
            nodes.push_back(new Node(x, y, z));
            matrix[x][y][z] = true;
        }
    }

    void addEdge(int idx1, int idx2, double weight) {
        adjList[idx1].emplace_back(idx2, weight);
        adjList[idx2].emplace_back(idx1, weight);
    }

    double distance(Node* a, Node* b) {
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2)); // Pythagorean distance
    }

    void createEdges() {
        for (size_t i = 0; i < nodes.size(); ++i) {
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                double dist = distance(nodes[i], nodes[j]);
                addEdge(i, j, dist);
            }
        }
    }

    vector<int> dijkstra(int startIdx) {
        vector<double> dist(nodes.size(), numeric_limits<double>::infinity()); // Distance array
        vector<int> prev(nodes.size(), -1); // Previous node tracking
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq; // Min-heap priority queue

        dist[startIdx] = 0;
        pq.emplace(0, startIdx);

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& [v, weight] : adjList[u]) {
                double alt = dist[u] + weight;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    pq.emplace(alt, v);
                }
            }
        }
        return prev; // Return shortest path tree
    }
};

#endif