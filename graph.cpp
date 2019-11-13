#include "graph.h"

/*
    This is implementation for graph class.
    Coded by Alistaire and Youssef
*/

void vertex::operator=(const vertex &u){
  this->id = u.id;
  this->visited = u.visited;
  this->processed = u.processed;
}

string vertex::toString() const{
  stringstream s;
  string item;
  s << id;
  s >> item;
  return item;
}

string edge::toString() const{
  stringstream s;
  string item;
  s << "<" << start << ":" << dest << ";" << weight << ">";
  s >> item;
  return item;
}

graph::graph(string file){
  make_mx(file);
  insert(matrix);
  make_list();
}


void graph::insert(vector<vector<int> > matrix){
  for (int i = 0; i < matrix.size(); i++){
    vertex v(i);
    V.push_back(v);
    for(int j = 0; j< matrix[i].size(); j++)
      if(matrix[i][j]!=0){
        edge e(i, j, matrix[i][j]); //start, dest, weight
        E.push_back(e);
      }
  }
}

void graph::make_mx(string file){
  ifstream i;
  i.open(file);
  string line, no_space;
  int size;

  getline(i, line);                         //reading line by line                            //if first line,
  size = stoi(line);
  matrix.resize(size);

  for(int x =0; x<size;x++){
    getline(i, line);
    line = rm_space(line);                  //removing space
    for (int j = 0; j < line.length();j++){  //moving over each number
      matrix[x].push_back(line[j] - CHAR_O);
    }
  }

  i.close();
}

void graph::make_list(){
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix[i].size(); j++)
      if (matrix[i][j] != 0)
        adj_list[i].push_back(j);
  }
}

string graph::rm_space(string str){
  string retStr = "";
  for (char c: str){
    if (c != ' ')
      retStr += c;
  }
  return retStr;
}

void graph::dfs(){
    stack<vertex> s;
    V[0].visited = true;
    cout<<V[0]<<" ";
    s.push(V[0]);
    while(!s.empty()){
      cout<<"here"<<endl;
      vertex u(s.top());
      s.pop();
      for(int i = 0; i<adj_list[u.id].size();i++){
        vertex* temp =  findV(adj_list[u.id][i]);
        if(!temp->visited){
          cout<<*temp<<" ";
          temp->visited = true;
          s.push(*temp);
        }
      }
      cout<<endl;
      u.processed =true;
    }

}

vertex* graph::findV(int n) const{
  for (vertex v: V)
    if (v.id == n)
      return new vertex(v);

  //throw non existing vertex exception
}

void graph::display() const{
  cout<<"Adjacency MATRIX:"<<endl;
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  cout << endl;

  cout<<"Adjacency List:"<<endl;
  for (auto pair: adj_list){
    cout << pair.first << ": [";
    for (int i = 0; i < pair.second.size(); i++){
      cout << pair.second[i];
      if (i != pair.second.size() - 1)
        cout << ",";
    }
    cout << "]" << endl;
  }
    cout <<  endl;

  cout<<"VERTEX LIST:"<<endl;
  for (auto item: V){
    cout << item << " ";
  }
  cout <<  endl;

  cout<<"EDGE LIST:"<<endl;
  for (auto item: E){
    cout << item << " ";
  }

  cout << endl;
}
