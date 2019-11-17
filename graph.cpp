#include "graph.h"

/*
  this is implementation file for graph ADT.
  Coded by Youssef and Alistaire.
*/


graph::graph(string file, int opt){
  //constructor #1
  switch(opt){
    case 1:        //kattis:stars
      make_star_list(file);
      break;
    case 2:        //kattis:coast
      break;
    default:
      make_mx(file);
      insert(matrix);
      make_list();
      getInbound();
  }
}

void graph::topologicalsort(){
  /*
    this function executes the topological sort.

    PreCondition:There should not be cycle nor unreachable vertex.
  */
  queue<int> q;             //setting up
  vector<int> v = V;

  for (int key: V){         //find all the ones with 0 indegree
    if(inbound[key]==0){    //if it is a zero then add it to the queue
      q.push(key);
    }
  }

  while(!q.empty()){        //while the queue is not empty
    int u = q.front();      //set u to be the front vertex in the stack
    q.pop();
    cout << u << " ";
    for(int n: adj_list[u]){//for all the successors of u
          inbound[n]-=1;    //decrement the indegree of the current indegree
          if(inbound[n]==0){//if the indegree is 0 push the vertex into the stack
            q.push(n);
          }
    }
  }
}

void graph::getInbound(){
  //this gets the indegree numbers for all the vertices.

  /*
    this loop adds all of the values in our vertex list
    to our map and sets them to zero
  */
  for (int key: V)
    inbound[key]= 0;          //sets to 0 in case there is none

  for (int key: V){           //soo for every vertex...
    for(int z: adj_list[key]){//add one TO THE NEIGHBOR'S value in the map because thats inbound to it
      inbound[z] += 1;
    }
  }
}


void graph::insert(vector<vector<int> > matrix){
  //this function insert vertex from the matrix.
  for (int i = 0; i < matrix.size(); i++){
    V.push_back(i);
  }
}

void graph::make_mx(string file){
  /*
    this function generates the adjacency matrix based on the file.
    PreCondition: file should not be empty string.
  */
  ifstream i;
  i.open(file);
  string line, no_space;
  int size;

  //reading line by line
  getline(i, line);                         //if first line,
  size = stoi(line);
  matrix.resize(size);

  for(int x =0; x<size;x++){
    getline(i, line);
    line = rm_space(line);                   //removing space
    for (int j = 0; j < line.length();j++){  //moving over each number
      matrix[x].push_back(line[j] - CHAR_O);
    }
  }

  i.close();
}

void graph::make_star_list(string file){
  ifstream f;
  f.open(file);
  string line;
  int *rowCol, row, col;
  int case_1, case_2;
  case_1 = case_2 = 0;         //initializing

  //case 1.
  stars(1, f);
 
  V.clear();      //resetting
  adj_list.clear();
  cout << endl;
  
  //case2
  stars(2, f);

  f.close();
}

void graph::stars(int i, ifstream &f){
  string line;
  getline(f, line);             //reading the first row and column 
  int* rowCol = getRowCol(line);
  int row = rowCol[0]; 
  int col = rowCol[1];

  for (int i = 0; i < col; i++){//filling vertex list
    V.push_back(i);
  }

  line = "";
  for (int i = 0; i < row; i++){
    getline(f, line);           //getting line

    for (int j = 0; j < col; j++){
      if (line[j] != '#')
        adj_list[i].push_back(j);
    }
    line = "";
  }

  int Case = 0;
  string str = dfs();
  for (int i = 0; i < str.length(); i++){
    if (str[i] == ',')
      Case++;  
  }

  showList();
  showVertexList();
  cout << dfs() << endl;

  cout << "Case " << i << ": " << Case << endl;

  delete rowCol;  //freeing memory
}

int* graph::getRowCol(string line){
  int* rowCol = new int[2];
  int split, row, col;
  string s_row, s_col;

  //finding the split between row and col int
  for (int i = 0; i < line.length(); i++)
    if (line[i] == ' '){
      split = i;
      break;
    }

  //getting row 
  s_row = "";
  for (int i = 0; i < split; i++)
    s_row += line[i];
  row = stoi(s_row);

  //getting col
  s_col = "";
  for (int i = split + 1; i < line.length(); i++)
    s_col += line[i];
  col = stoi(s_col);

  rowCol[0] = row;
  rowCol[1] = col;
  return rowCol;
}

void graph::make_coast_mx(string file){

}

void graph::make_list(){
  /*
    this function generates the adjacency list.
    PreCondition: adjacency matrix has to be initiated.
  */
  for (int i = 0; i < matrix.size(); i++){
    adj_list[i].resize(0);                  //needed to ensure if empty it will show an empty list
    for (int j = 0; j < matrix[i].size(); j++)
      if (matrix[i][j] != 0)
        adj_list[i].push_back(j);
  }
}

string graph::rm_space(string str){
  /*
    this function removes any white space in the string.
    PreCondition: input string has to be valid string.
  */
  string retStr = ""; //basic new string
  for (char c: str){  //for each char from input string
    if (c != ' ')     //if not white space
      retStr += c;    //concatenate.
  }
  return retStr;      //return the result.
}

string graph::dfs(){
    /*
      this function executes depth first search.
      PreCondition: vertex list should not be empty.
    */
    string str = "";
    stringstream ss;

    stack<int> s;
    map<int, int> colors; //1:w 2:g 3:b

    for (int key: V){ // make em all white
      colors[key] = 1;
    }

    s.push(V[0]);
    colors[V[0]] = 1;

    while(!s.empty()){
      int u(s.top());
      s.pop();
      for (int v: adj_list[u]){
        if(colors.find(v)->second == 1){
          colors[v] = 2;
          s.push(v);
        }
      }
      // cout<< u << " ";
      ss << u << ",";

      colors[u] = 3;
    }
    // cout << endl;
    ss >> str;
    return str;
}



void graph::display() {
  /*
    this function displays the information of the graph.
    PreCondition: matrix, list, vertex list has to be initiated.
  */
  cout<<"Adjacency Matrix:"<<endl;
  showMatrix();

  cout<<"Adjacency List (outbound):"<<endl;
  showList();

  cout<<"Inbound List:"<<endl;
  showInboundList();

  cout<<"VERTEX LIST:"<<endl;
  showVertexList();

  cout<<"Depth first Search:"<<endl;
  cout << dfs() << endl;

  // cout<<"Topologicalsort sort:"<<endl;
  // topologicalsort();

  cout << endl;
}

void graph::showMatrix(){
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

void graph::showList(){
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
}

void graph::showInboundList(){
   for (auto pair: inbound){
    cout << pair.first << ": [";
    cout << pair.second;
    cout << "]" << endl;
  }
  cout <<  endl;
}
    
void graph::showVertexList(){
  for (auto item: V){
    cout << item << " ";
  }
  cout <<  endl;
}
