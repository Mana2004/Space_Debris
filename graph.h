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

    void addNode(int x, int y, int z) {
        nodes.push_back(new Node(x, y, z));
        cout << "Added Node: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    double distance(Node* a, Node* b) {
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
    }

    void createEdges() {
        for (size_t i = 0; i + 1 < nodes.size(); ++i) {
            double dist = distance(nodes[i], nodes[i + 1]);
            adjList[i].emplace_back(i + 1, dist);
            adjList[i + 1].emplace_back(i, dist);
        }
    }
    

    vector<int> ucs(int startIdx) {
        vector<double> cost(nodes.size(), numeric_limits<double>::infinity());
        vector<int> prev(nodes.size(), -1);
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    
        cost[startIdx] = 0;
        prev[startIdx] = startIdx; // Set the start node's predecessor to itself
        pq.emplace(0, startIdx);
    
        while (!pq.empty()) {
            auto [currCost, u] = pq.top();
            pq.pop();
    
            for (auto& [v, w] : adjList[u]) {
                double newCost = currCost + w;
                if (newCost < cost[v]) {
                    cost[v] = newCost;
                    prev[v] = u;
                    pq.emplace(newCost, v);
                }
            }
        }
    
        return prev;
    }
    
};

#endif
