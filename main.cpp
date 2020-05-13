#include "Graph.h"
#include "Timer.h"
#include <queue>
#include <limits>

using namespace std;


int MAX = numeric_limits<int>::max();

vector<int> computeShortestPath(Graph g, int node){

  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;

  vector<int> D(g.size(), MAX);

  
  
  q.push(make_pair(0,node));
  D[node] = 0;

  while(!q.empty()){
    int u = q.top().second;
    q.pop();

    list<int> z = g.getConnectedNodes(u);
    int num_connections = z.size();

    
    for(int i = 0; i < num_connections; i++){
      
      int n = z.front();
      z.pop_front();
      int weight = g.getEdgeWeight(u,n);

      if(D[n] > D[u] + weight){
        D[n] = D[u] + weight;
        q.push(make_pair(D[n],n));
      }

      


    }

  }



return D;
};

vector<vector<int> > computeAllPairsShortestPath(Graph g){

  //####compute all possible shortest paths by calling the Dijkstra's Algorithm on each pair of nodes

vector<vector<int> > returnMatrix; 
  for(int i = 0; i < g.size(); i++){
    returnMatrix.push_back(computeShortestPath(g,i));
  }
  return returnMatrix;

};



bool compareResults(Graph g, Matrix a, Matrix b){

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g.size(); j++){
      if(a[i][j] != b[i][j]){
        return false;
      }
    }
  }

  return true;
}

void print(Matrix v){
    //### you can implement this for debugging purposes

    int size = v.size();
  for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
  }

int main(){

  //create graph as a random matrix
  Graph g(10,10);
  cout << "Graph generated " << endl;

  g.print();

  //compute shortest path
  Timer time;
  time.start();
  Matrix a = computeAllPairsShortestPath(g);
  time.stop();
  cout << "Time with Dijkstra's algorithm: " << time.getElapsedTimeInSec() << endl;


};
