#include "graph.h"
#include "assert.h"
/*
    this file tests graph class.
    Coded by Alistiare and Youssef
*/

int main(){
    //note:DFS will not work with topologicalsort test
    // because it is a directed graph  i do not know if thats a problem
    cout << "test case 1" << endl;
    graph test1("test.txt");
    test1.display();
    assert(test1.dfs() == "0,2,4,3,1,");

    cout << "test case 2" << endl;
    graph test2("test2.txt");
    test2.display();
    assert(test2.dfs() == "0,5,2,4,3,1,");

    cout << "test case 3" << endl;
    graph test3("test3.txt");
    test3.display();
    assert(test3.dfs() == "0,9,3,4,8,7,6,5,2,1,");

    return 0;
}
