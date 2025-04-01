#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "graph.h"

using namespace std;

class FileReader {
public:
    static void readFromFile(Graph& graph, const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open the file!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            int label, x, y, z;
            char ch;
            stringstream ss(line);
            if (ss >> label >> ch >> x >> ch >> y >> ch >> z) {
                cout << label << " (" << x << ", " << y << ", " << z << ")" << endl;
                graph.addNode(x - 1, y - 1, z - 1);
            }
        }
    }
};

#endif