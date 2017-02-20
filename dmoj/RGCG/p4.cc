#include <bits/stdc++.h>

#define INF 1e9 

using namespace std;
typedef vector<int> VI; 
typedef pair<int, int> IPair; 

int N, M;
int dist[1000000]; 
int scene[1000000]; 

vector<vector<IPair>  > adjList;

vector<int> top_order; 

bool visited[1000000];
bool done[1000000];

void dfs(int i)
{
  if(visited[i]){
    cout << " " << -1 << endl;
    exit(0); 
    return; 
  }

  visited[i] = true;
  for(int j = 0; i<adjList[i].size(); i++){
    if(!done[adjList[i][j].first]){
      dfs(adjList[i][j].first); 
    }
  }
  done[i] = true;
  visited[i] = false;
  top_order.push_back(i); 
}

void top(){
  for(int i = 0; i<N; i++){
    visited[i] = false;
    done[i] = false; 
  }

  for(int i = 0; i<N; i++){
    if(!done[i]){
      dfs(i);
    }
  }

}


void getDist(){

  for(int i = 0; i<N; i++){
    scene[i] = 0; 
    dist[i] = -1;
    visited[i] = false;
  }

  dist[0] = 0; 
  scene[0] = 1; 
  for(int i = 0; i<top_order.size(); i++){
    int next = top_order[top_order.size() -1 - i]; 
    for(int k = 0; k<adjList[next].size(); k++){
      
      int a = next;
      int b = adjList[next][k].first;
      int w = adjList[next][k].second; 

      if(dist[b] == dist[a] + w){
        scene[b] = max(scene[a] + 1, scene[b]); 
      }
      if(dist[b] < dist[a] + w){
        dist[b] = dist[a] + w;
        scene[b] = scene[a] + 1;
      }
    }
  }
}
int main(){
  cin >> N >> M; 

  adjList.resize(N); 
  for(int i = 0; i<M; i++){
    int a,b,d;
    cin >> a >> b >> d;
    a--;
    b--;
    adjList[a].push_back(make_pair(b,d)); 
  }
  top(); 
  getDist(); 
  cout << dist[N - 1] << " " << scene[N - 1]; 
}
