#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define INF 1e9

using namespace std;
typedef pair<int, int> IPair;

int N, M, D;

int * bfs(vector<vector<pair<int,int>>> & adjList){
  priority_queue<pair<int, int>> pq; 

  bool visited[N]; 
  fill(visited, visited + N, false); 


  int counted = 0; 

  int *minEdge = new int[N];
  fill(minEdge, minEdge + N, -1); 

  minEdge[0] = INF; 

  pq.push(make_pair(-1,0)); 


  while(!pq.empty())
  {
    int curr = pq.top().second; 
    int weight = pq.top().first; 
    pq.pop();
    
    if(visited[curr]) continue;

    visited[curr] = true;
    
    for(int i = 0; i<adjList[curr].size(); i++){
      IPair next = adjList[curr][i]; 
      if(!visited[next.second]){
        minEdge[next.second] = max(minEdge[next.second], min(minEdge[curr], next.first)); 
        pq.push(next);
      }
    }
  }
  return minEdge;
}

int main()
{
  cin >> N >> M;

  vector<vector<pair<int,int>>> adjList; 
  adjList.resize(N); 
  for(int i = 0; i<M; i++){
    int a,b,w;
    cin >> a >> b >> w;
    a--;
    b--;
    adjList[a].push_back(make_pair(w,b));
    adjList[b].push_back(make_pair(w,a));
  }
  
  int *dists = bfs(adjList); 
  cout << 0 << endl;
  for(int i = 1; i < N; i++){
    cout << dists[i] << endl;
  }
}

