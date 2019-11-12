#include "graph.h"

/*
    This is implementation for graph class.
    Coded by Alistaire and Youssef
*/

template<class T> //constructor
vertex<T>::vertex(T* item = NULL){
    this->key = (item != NULL)?new T(*item):NULL;
}