#include "graph.h"
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
    
    
    cout << "test case 2" << endl;
    graph test2("test2.txt");
    test2.display();
    
    cout << "test case 3" << endl;
    graph test3("test3.txt");
    test3.display();

    return 0;
}
