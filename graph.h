#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    This is ADT for graph class.
    Coded by Alistaire and Youssef
*/

template<class T>
class vertex{
public:
    int id;                      //integer identifier
    T* key;                      //key item
    vector<vertex<T>*> inbound;  //for indegree
    vector<vertex<T>*> outbound; //for outdegree

    vertex(T* item = NULL);      //constructor
};

template<class T>
class graph{
private:
    int size = 0;

    graph();

};

#include "graph.cpp"
#endif