#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef vector<vector<int> > Matrix;

class Graph{

  Matrix graph;

public:
  Graph(int nNodes, int nEdges){
    // you don't have to change anything here. This function will generate a random weighted graph given the
    // desired parameters (number of nodes and number of edges)
    srand (time(NULL));

    graph = Matrix(nNodes, vector<int>(nNodes,0));

    for(int i=0; i<nEdges; i++){
      //random weight
      int weight = rand()%(101);
      int node1, node2;

      do{
        node1 = rand()%(nNodes);
        node2 = rand()%(nNodes);
      }while(node1 == node2 && !connected(node1,node2));

      graph[node1][node2] = graph[node2][node1] = weight;
    }

  }

  int size(){
    //### return the number of nodes in the graph
    return graph[0].size();
  }

  list<int> getConnectedNodes(int n){
    //### return a list with the nodes connected to node
    list<int> returnList;

    for(int i = 0; i < graph[n].size(); i++){
      if(graph[n][i] != 0 ){
        returnList.push_back(i);
      }
      
    }
    return returnList;
  }

  int getEdgeWeight(int n, int n2){
    //### return the weight assigned to a node
    return graph[n][n2];
  }

  bool connected(int n, int n2){
    //### return true if the two nodes are connected
    if(graph[n][n2] == 0){
      return false;
    }else{
      return true;
    }
  }

  void print(){
    //### you can implement this for debugging purposes

    int size = graph[0].size();
  for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
  }

};
