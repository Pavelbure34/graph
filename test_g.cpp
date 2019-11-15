#include "graph.h"
/*
    this file tests graph class.
    Coded by Alistiare and Youssef
*/

int main(){
    graph test1 ("topotest.txt");
    test1.display(); //**note  DFS will not work with topologicalsort test because it is a directed graph  i do not know if thats a problem
    // test1.dfs();
    // test1.topologicalsort();
    return 0;
}
