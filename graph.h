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
    vector<int> V;                    //list of verteces
    vector<vector<int> > matrix;      //adjacency matrix
    map<int, vector<int> > adj_list;  //adjacency list
    map<int, int> inbound;            //inbound verteces

public:
    graph(string file, int opt = 0);      //constructor #1

    void display();                   //showing graph information
    string dfs();                     //depth first search
    void topologicalsort();           //topological sort

    void showMatrix();
    void showList();
    void showInboundList();
    void showVertexList();

private:
    string rm_space(string str);      //remove the white space of the string
    void insert(                      //inserting matrix
        vector<vector<int> > matrix); 
    void make_mx(string file);        //making the matrix
    void make_star_list(string file); //making matrix for kattis star
    void make_coast_mx(string file);  //making matrix for kattis coast
    void make_list();                 //making the list based on the matrix
    void initialize();                //initializing the data
    void getInbound();                //retrieving inbound verteces
    bool isCycle() const;             //detecting cycles

    int* getRowCol(string line);      //extracting row and col from counting stars
    void stars(int i, ifstream &f);   //analyze the bit map and count the number of the stars.
};
#include "graph.cpp"
#endif
