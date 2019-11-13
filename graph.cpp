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
  i.open(file)
}
