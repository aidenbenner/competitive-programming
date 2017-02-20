#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef vector<vector<int>> AdjList; 
vector<int> DFS(AdjList & al, int source)
{
  vector<int> dist; 
  dist.resize(al.size()); 
  bool visited[al.size()]; 
  for(int i = 0; i<al.size(); i++){
    dist[i] = -1; 
    visited[i] = false; 
  }

  queue<int> pq; 
  pq.push(source); 
  dist[source] = 0; 
  
  while(!pq.empty()){
    queue<int> frontier; 
    while(!pq.empty())
    {
      int curr = pq.front(); 
      pq.pop(); 
      visited[curr] = true;
      for(int i = 0; i<al[curr].size(); i++){
        int next = al[curr][i]; 
        if(!visited[next]){
          dist[next] = dist[curr] + 1;
          frontier.push(next); 
        }
      }
    }
    pq = frontier;
  }
}


int main()
{
  AdjList al;
  al.resize(5); 
  al[0].push_back(1); 
  al[1].push_back(2); 
  al[2].push_back(3); 
  al[1].push_back(2); 
  al[4].push_back(2); 
  al[1].push_back(3); 

  vector<int> dist = DFS(al,0);

  for(int i = 0; i<dist.size(); i++){
    cout << dist[i] << endl;
  }
}
