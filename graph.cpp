#include "graph.h"

/*
    This is implementation for graph class.
    Coded by Alistaire and Youssef
*/


void graph::insert(int n, int w){
  vertex v(n);
  if(V.empty()){
    V.push_back(v);
  }
  else{
    V.push_back(v);
    edge e (n,V[n-1],w);
    E.push_back(e);
  }
}

void graph::make_mx(string file){
  ifstream i;
  stringstream s;
  i.open(file);
  string line, no_space;

  int j = 0;
  while (!i.eof()){
    getline(i, line);         //reading line by line
    
    if (j == 0){              //if first line,
      matrix.resize(stoi(line));
    }else{
      s << line;              //getting line
      s >> no_space;          //removing spaces;
      for (char c: no_space){ //moving over each number
        matrix[j].push_back(int(c) - int(CHAR_O));
      }
    }  
    
    j++;
  }
}
