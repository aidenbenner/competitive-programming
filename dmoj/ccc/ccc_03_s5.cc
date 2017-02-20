#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define INF 1e9

using namespace std;
typedef pair<int, int> IPair;


int C,R,D; 
int bfs(vector<vector<pair<int,int>>> adjList, bool dest[]){
  priority_queue<pair<int, int>> pq; 

  bool visited[C]; 
  memset(visited,false,sizeof(visited));

  int minEdge = INF;
  pq.push(make_pair(INF,0)); 

  int counted = 0; 


  while(!pq.empty())
  {
    int curr = pq.top().second; 
    int weight = pq.top().first; 
    pq.pop();


    if(visited[curr]) continue;

    visited[curr] = true;
    if(dest[curr]){ counted++; dest[curr] = false; }
    minEdge = min(minEdge, weight); 
    if(counted == D) return minEdge; 
    for(int i = 0; i<adjList[curr].size(); i++){
      IPair next = adjList[curr][i]; 
      if(!visited[next.second]){
        pq.push(next);
      }
    }
  }
}

int main()
{
  cin >> C >> R >> D;

  bool dest[C]; 
  memset(dest,false,sizeof(dest)); 

  vector<vector<pair<int,int>>> adjList; 
  adjList.resize(C); 
  for(int i = 0; i<R; i++){
    int a,b,w;
    cin >> a >> b >> w;
    a--;
    b--;
    adjList[a].push_back(make_pair(w,b));
    adjList[b].push_back(make_pair(w,a));
  }
  
  for(int i = 0; i < D; i++){
    int t;
    cin >> t;
    dest[t - 1] = true;
  }

  cout << bfs(adjList, dest) << endl;
}
