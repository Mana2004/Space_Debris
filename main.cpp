#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
//#include <cstdlib>
//#include <cstdio>

using namespace std;

int main() {

  /*bool matrix[10][10][10] = {false};
  float distance[1000];
  
  ifstream MyReadFile("input.txt");
  string line;

  if (!MyReadFile) {
      cerr << "Error: Could not open the file!" << endl;
      return 1;
  }

  while (getline(MyReadFile, line)) {

    int label;
    char ch; 
    int x, y, z; 
    stringstream ss(line); 
    ss >> label >> ch >> x >> ch >> y >> ch >> z >> ch;

    cout << label << x << y << z << endl;

    matrix[x-1][y-1][z-1]={true};      
  }

  MyReadFile.close();

  for(int i=0; i < 10; i++){
    for(int j=0; j < 10; j++){
      for(int k=0; k < 10; k++){
        if(matrix[i][j][k]){
        }
        //cout << matrix[i][j][k] << endl;
      }
    }
  }

  return 0;
}


class Graph{
  vector<vector<bool> > adjlist;
public:
  Graph(int n){
    adjlist = vector<vector<bool> >(n, vector<bool>(n, 0));
  }

void edge(int x, int y, int z){
  adjlist[x][y][z] = {true};
  adjlist[z][y][x] = {true};
  adjlist[z][x][y] = {true};


}*/

};