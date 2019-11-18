#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
using namespace std;

class graph{
private:
    vector<int> V;                    //list of verteces
    map<int, int> visited;            //inbound verteces
    vector<vector<int> > matrix;      //adjacency matrix
    map<int, vector<int> > adj_list;  //adjacency list

public:
  graph(){}

  void dfsStar(int start){
      stack<int> s;
      s.push(start);
      while(!s.empty()){
        int u(s.top());
        s.pop();
        for (int v: adj_list[u]){
          if(visited[v] == 0){
            visited[v]=1;
            s.push(v);
          }
        }
      }
  }

  void make_star_list(int row, int col, int c){
    //making matrix for kattis star
    string line;
    matrix.resize(row);
    for(int r = 0; r < row; r++){
      cin>>line;
      for (int c = 0; c < col; c++){           //moving over each number
        if(line[c]=='#'){
          matrix[r].push_back(0);
        }
        else{
          matrix[r].push_back(1);
        }
      }
    }
    stars(c);
  }

private:
    void stars(int i){
      //analyze the bit map and count the number of the stars.
      int count=0;
      int d = 1; //id for the vertices

      for (int r = 0; r < matrix.size(); r++){ //get the vertices
        for (int c = 0; c < matrix[r].size(); c++){
          if (matrix[r][c]!=0){
            matrix[r][c] = d;
            V.push_back(d);
            visited[d] = 0;
            d++;
          }
        }
      }

      int row = matrix.size();
      int col = matrix[0].size();
      for (int i = 0; i < row; i++){ //get the vertices neighbors
        for (int j = 0; j < col; j++){
          if (matrix[i][j]!=0){
            if(i+1<row && matrix[i+1][j]!=0){
              adj_list[matrix[i][j]].push_back(matrix[i+1][j]);
            }
            if(i-1>=0 && matrix[i-1][j]!=0){
              adj_list[matrix[i][j]].push_back(matrix[i-1][j]);
            }
            if(j+1<col && matrix[i][j+1]!=0){
              adj_list[matrix[i][j]].push_back(matrix[i][j+1]);
            }
            if(j-1>=0 && matrix[i][j-1]!=0){
              adj_list[matrix[i][j]].push_back(matrix[i][j-1]);
            }
          }
        }
      }

      for(int x: V){
        if(visited[x]==0){
          dfsStar(x);
          count++;
        }
      }
      cout<<"Case "<< i << ": " << count << endl;
    }
};

int main(){
  int c = 1;
  string sRow, sCol;
  while(cin>>sRow>>sCol){
    graph test;
    int row = stoi(sRow);
    int col = stoi(sCol);
    test.make_star_list(row, col, c);
    c++;
  }
  return 0;
}
