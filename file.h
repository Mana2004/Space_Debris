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
    static void readFromFile(Graph& graph, const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open the file!" << endl;
            return;
        }

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
};

#endif
