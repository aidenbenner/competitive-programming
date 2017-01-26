#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>
#include <iostream>
#include <cstring>
#include <utility>
#include <bitset>

#define INF 1e9 

using namespace std;
typedef pair<int,int> IPair; 

vector< vector<IPair> > adjList; 
int dist[1001]; 

int N, M;

void sp(int source)
{
  bitset<1001> visited;
  visited.reset(); 

  dist[source] = 0; 

  bool running = true; 
  while(running)
  {
    //extract min.. too lazy to use a pq  
    int min = -1; 
    for(int i = 0; i<N; i++){
      if(min == -1 || dist[i] < dist[min]){
        if(visited[i]){
          continue; 
        }
        min = i; 
      }
    }

    if(min == -1 || dist[min] == INF){
      running = false; 
      break; 
    }

    visited[min] = 1; 

    for(int i = 0; i<adjList[min].size(); i++){
      int B = adjList[min][i].first; 
      int W = adjList[min][i].second;
      if(dist[B] > dist[min] + W){
        dist[B] = dist[min] + W; 
      }
    }
  }
}

int main()
{
  for(int i = 0; i<1001; i++){
    dist[i] = INF;
  }

  cin >> N >> M; 

  adjList.resize(N); 

  for(int i = 0; i<M; i++)
  {
    int A, B, W;
    cin >> A >> B >> W;
    A--;
    B--;
    adjList[A].push_back(make_pair(B,W)); 
    adjList[B].push_back(make_pair(A,W)); 
  }

  sp(0); 

  for(int i = 0; i<N; i++){
    if(dist[i] == INF){
      cout << -1 << endl;
      continue;
    }
    cout << dist[i] << endl; 
  }
}

