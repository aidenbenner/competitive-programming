#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef vector<vector<int>> AdjList; 

bool bfs(AdjList adj, int p, int q){
  bool visited[adj.size()]; 
  fill(visited,visited + adj.size(), false); 
  queue<int> pq; 
  pq.push(p);
  
  while(!pq.empty()){
    int curr = pq.front();
    pq.pop(); 
    if(curr == q){ return true;}
    if(visited[curr]) continue;
    visited[curr] = true;

    for(int i = 0; i<adj[curr].size(); i++){
      pq.push(adj[curr][i]);
    }
  }
  return false;
}


int main()
{
  int N, M;
  cin >> N >> M; 
  
  AdjList adj; 
  adj.resize(N); 
  for(int i = 0; i<M; i++){
    int a,b;
  
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b); 
  }

  int p,q; 
  cin >> p >> q;
  p--;
  q--;

  if(bfs(adj,p,q)) cout << "yes";
  else if(bfs(adj,q,p)) cout << "no"; 
  else cout << "unknown"; 
}
