#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;
/*
    This is ADT for graph class.
    Coded by Alistaire and Youssef
*/

#define CHAR_O '0'

// class vertex{
// public:
//     int id;
//     bool visited = false;
//     bool processed = false;
//
//     vertex();                 //default constructor
//     vertex(int id):id(id){};  //2nd constructor
//     vertex(const vertex &u):
//       id(u.id), visited(u.visited), processed(u.processed){};
//
//     string toString() const;
//     void operator=(const vertex &u);
//     friend ostream& operator<<(ostream& o, vertex v){
//       o << v.toString();
//       return o;
//     }
// };
//
// class edge{
// public:
//     int start;
//     int dest;
//     int weight;
//
//     edge():weight(0){};
//     edge(int start, int dest):start(start), dest(dest), weight(0){};
//     edge(int start, int dest, int weight):start(start), dest(dest), weight(weight){};
//
//     string toString() const;
//     friend ostream& operator<<(ostream& o, edge e){
//       o << e.toString();
//       return o;
//     }
// };

class graph{
private:
    vector<int> V;
    vector<vector<int> > matrix;
    map<int, vector<int> > adj_list;

public:
    graph(string file);
    graph(graph &g);
    // ~graph();

    void display() const;
    void dfs();

private:
    string rm_space(string str);
    void insert(vector<vector<int> > matrix);
    void make_mx(string file);
    void make_list();
    void initialize();
    bool isCycle() const;
    // vertex findV(int n) const;
};

#include "graph.cpp"
#endif
