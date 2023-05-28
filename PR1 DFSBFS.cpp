#include <iostream>
#include <list>
using namespace std;
int numVertices;
  list<int> *adjLists;
  bool *visited;

class Graph {
  
   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}
int dfsm() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.DFS(2);

return 0; 
}

class Graphs {
  

   public:
  Graphs(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graphs::Graphs(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graphs::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

// BFS algorithm
void Graphs::BFS(int startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}
int main()
{
    while(7){
        cout<<"Enter Your Choice\n";
    cout<<"1.BFS Algorithm\n";
    cout<<"2.DFS Algorithm\n";
    cout<<"3.Enter any key to exit\n\n";
    cout<<"Enter your choice:";
    int ch;
    cin>>ch;
    switch(ch){
       case 1: {
       Graphs gs(4);
  gs.addEdge(0, 1);
  gs.addEdge(0, 2);
  gs.addEdge(1, 2);
  gs.addEdge(2, 0);
  gs.addEdge(2, 3);
  gs.addEdge(3, 3);

  gs.BFS(2);

 
 
  break;
}
case 2:{
        dfsm();
        break;
      }
      default:
        return 0;
    }     
}
}
