#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
    This is ADT for graph class.
    Coded by Alistaire and Youssef
*/

class vertex{
public:
    int id;
    vector<int> ob;  //outbound

    vertex();        //default constructor
    vertex(int id);  //2nd constructor
};

class edge{
public:
    int start;
    int dest;
    int weight;

    edge():weight(0){};
    edge(int start, int dest):start(start), dest(dest), weight(0){};
    edge(int start, int dest, int weight):start(start), dest(dest), weight(weight){};
};

class graph{
private:
    vector<vertex> V;
    vector<edge> E;
    map<vector<int> > matrix;

public:
    graph(string file);
    graph(graph &g);

    void insert(int n);

    void make_mx(string file);

};

#include "graph.cpp"
#endif
