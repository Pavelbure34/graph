#include "graph.h"


graph::graph(string file){
  make_mx(file);
  insert(matrix);
  make_list();
}

void graph::topologicalsort(){

  for (int r = 0; r < matrix.size(); r++){
    for (int c = 0; c < matrix[r].size(); c++)
      
  }


}

bool graph::isCycle() const{

}

void graph::insert(vector<vector<int> > matrix){
  for (int i = 0; i < matrix.size(); i++){
    V.push_back(i);
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
    stack<int> s;
    map<int, int> colors; //1:w 2:g 3:b

    for (int key: V){ // make em all white
      colors[key] = 1;
    }

    // cout<<V[0]<<" ";
    s.push(V[0]);
    colors[V[0]] = 1;

    while(!s.empty()){
      int u(s.top());
      s.pop();
      for (int v: adj_list[u]){
        if(colors.find(v)->second==1){
          // cout<<v<<" "; //if gray means visiting
          colors[v] = 2;
          s.push(v);
        }
      }
      cout<<u<<" ";
      colors[u]=3;
    }
    cout<<endl;
}



void graph::display() {
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
  cout <<  endl;

  cout<<"Depth first Search:"<<endl;
  dfs();

  cout << endl;
}
