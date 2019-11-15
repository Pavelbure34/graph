#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
/*
    This is ADT for graph class.
    Coded by Alistaire and Youssef
*/

#define CHAR_O '0'


class graph{
private:
    vector<int> V;
    vector<vector<int> > matrix;
    map<int, vector<int> > adj_list;
    map<int, int> inbound;

public:
    graph(string file);
    graph(graph &g);

    void display();
    void dfs();
    void topologicalsort();

private:
    string rm_space(string str);
    void insert(vector<vector<int> > matrix);
    void make_mx(string file);
    void make_list();
    void initialize();
    void getInbound();
    bool isCycle() const;
};

#include "graph.cpp"
#endif
