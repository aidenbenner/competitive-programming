#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<vector<int>> adjList;


bool visited[100001];
bool pho[100001]; 

int N, M;

int count_edges(int source)
{
  if(visited[source]){
    return 0; 
  }
  visited[source] = true;

  int out = 0; 
  for(int i = 0; i<adjList[source].size(); i++){

    out += count_edges(adjList[source][i]);
    cout << i <<  "   " << out << endl;
  }

  if(pho[source]){
    return 1+out;
  }
  if(out == 0){
    return 0;
  }
  return 1 + out;
}


int DFS(int source){
  for(int i = 0; i<N + 1; i++){
    visited[i] = false;
  }

  queue<int> pq; 
  pq.push(source);

  int next = source;
  int deep_res = source; 
  int dis = 0;
  int useful = 0; 
  while(!pq.empty()){
    dis++; 
    next = pq.front();
    pq.pop();
    visited[next] = true;
    if(pho[next]){
      deep_res = next;
    }
    for(int i = 0; i<adjList[source].size(); i++){
      int curr = adjList[source][i];
      if(!visited[curr]){
        pq.push(curr); 
      }
    }
  }

  return deep_res;
}


int DFS_dist(int source){
  for(int i = 0; i<N + 1; i++){
    visited[i] = false;
  }

  queue<int> pq; 
  pq.push(source);

  int next = source;
  int deep_res = source; 
  int max_dis = 0; 
  int dis = 0;
  while(!pq.empty()){
    dis++; 
    next = pq.front();
    pq.pop();
    visited[next] = true;
    if(pho[next]){
      deep_res = next;
      if(dis > max_dis){
        max_dis = dis;
      }
    }
    for(int i = 0; i<adjList[source].size(); i++){
      int curr = adjList[source][i];
      if(!visited[curr]){
        pq.push(curr); 
      }
    }
  }

  return max_dis;
}


int main(){
  cin >> N >> M; 

  adjList.resize(N + 1); 
  for(int i = 0; i<N + 1; i++){
    pho[i] = false; 
    visited[i] = false;
  }

  int minInd = 0; 
  for(int i = 0; i<M; i++){
    int tmp; 
    cin >> tmp;
    pho[tmp] = true;
    minInd = tmp;
  }

  for(int i = 0; i<N-1; i++){
    int a,b; 
    cin >> a >> b;
    adjList[a].push_back(b); 
    adjList[b].push_back(a); 
  }

  int n = count_edges(minInd); 
  cout << (n) << endl;
  cout << 2 * (n) - (DFS_dist(DFS(minInd))) << endl; 
}
