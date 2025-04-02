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
                cout << "Edge created between Node " << i << " and Node " << j << " with weight " << dist << endl;
            }
        }
    }

    vector<int> dijkstra(int startIdx) {
        if (nodes.empty()) {
            cout << "Error: No nodes in the graph!" << endl;
            return {};
        }
        if (startIdx >= nodes.size()) {
            cout << "Error: Invalid start index!" << endl;
            return {};
        }
    
        vector<double> dist(nodes.size(), numeric_limits<double>::infinity());
        vector<int> prev(nodes.size(), -1);
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    
        dist[startIdx] = 0;
        pq.emplace(0, startIdx);
    
        cout << "Starting Dijkstra from Node " << startIdx << endl;
    
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
    
            cout << "Visiting Node " << u << " with current distance " << dist[u] << endl;
    
            for (auto& [v, w] : adjList[u]) {
                double alt = dist[u] + w;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    pq.emplace(alt, v);
                    cout << "Updating Node " << v << " with new distance " << alt << " via " << u << endl;
                }
            }
        }
        return prev;
    }    
};

#endif