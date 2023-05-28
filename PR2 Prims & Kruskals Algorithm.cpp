// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define edge pair<int, int>


#define INF 9999999

// number of vertices in grapj
#define Vi 5

// create a 2d array of size 5x5
//for adjacency matrix to represent graph

int G[Vi][Vi] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int prims() {
  int no_edge;  // number of edge

  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[Vi];

  // set selected false initially
  memset(selected, false, sizeof(selected));

  // set number of edge to 0
  no_edge = 0;

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < Vi - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < Vi; i++) {
      if (selected[i]) {
        for (int j = 0; j < Vi; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }

  return 0;
}
int main() {
    cout<<"\t\t\t\t\tGreedy Algorithm Approaches!\n\n";
    while(7){
    cout<<"1.Kruskals Algorithm\n";
    cout<<"2.Prim's Algorithm\n";
    cout<<"3.Enter any key to exit\n\n";
    cout<<"Enter your choice:";
    int ch;
    cin>>ch;
    switch(ch){
       case 1: {   
        Graph g(6);
        g.AddWeightedEdge(0, 1, 4);
        g.AddWeightedEdge(0, 2, 4);
        g.AddWeightedEdge(1, 2, 2);
        g.AddWeightedEdge(1, 0, 4);
        g.AddWeightedEdge(2, 0, 4);
                g.AddWeightedEdge(2, 1, 2);
        g.AddWeightedEdge(2, 3, 3);
        g.AddWeightedEdge(2, 5, 2);
        g.AddWeightedEdge(2, 4, 4);
        g.AddWeightedEdge(3, 2, 3);
        g.AddWeightedEdge(3, 4, 3);
        g.AddWeightedEdge(4, 2, 4);
        g.AddWeightedEdge(4, 3, 3);
        g.AddWeightedEdge(5, 2, 2);
        g.AddWeightedEdge(5, 4, 3);
        g.kruskal();
        g.print();
        break;
       }
      case 2:{
        prims();
        break;
      }
      default:
        return 0;
    }     
}
}
