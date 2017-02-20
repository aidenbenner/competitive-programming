#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 1e9

int R, C; 
void bfs(vector<vector<char>> & board, vector<vector<bool>> & visited, vector<vector<int>> &  dist){

  queue<pair<int, int>> pq; 
  pq.push(make_pair(0,0)); 
  dist[0][0] = 1; 

  while(!pq.empty())
  {
    int x = pq.front().first; 
    int y = pq.front().second; 
    pq.pop(); 
    if(x < 0 || y < 0) continue;
    if(x >= board[0].size()|| y >= board.size()) continue;
    if(visited[y][x]) continue;
    visited[y][x] = true;


    if(board[y][x] == '*') continue;

    if(board[y][x] == '-'){
      if(x >= 1){
        dist[y][x-1] = min(dist[y][x-1], dist[y][x] + 1);
        pq.push(make_pair(x-1,y));
      }
      if(x <= (int)dist[0].size() - 2){
        dist[y][x+1] = min(dist[y][x+1], dist[y][x] + 1);
        pq.push(make_pair(x+1,y));
      }
    }
    else if(board[y][x] == '|'){
      if(y >= 1){
        dist[y-1][x] = min(dist[y-1][x], dist[y][x] + 1);
        pq.push(make_pair(x,y-1));
      }
      if(y <= (int)dist.size() - 2){
        dist[y+1][x] = min(dist[y+1][x], dist[y][x] + 1);
        pq.push(make_pair(x,y+1));
      }

    }
    else{
      if(x >= 1){
        dist[y][x-1] = min(dist[y][x-1], dist[y][x] + 1);
        pq.push(make_pair(x-1,y));
      }
      if(x <= (int)board[0].size() - 2){
        dist[y][x+1] = min(dist[y][x+1], dist[y][x] + 1);
        pq.push(make_pair(x+1,y));
      }
      if(y >= 1){
        dist[y-1][x] = min(dist[y-1][x], dist[y][x] + 1);
        pq.push(make_pair(x,y-1));
      }
      if(y <= (int)board.size() - 2){
        dist[y+1][x] = min(dist[y+1][x], dist[y][x] + 1);
        pq.push(make_pair(x,y+1));
      }

    }
  }
}

int main()
{
  int N; 
  cin >> N;
  while(N--){

    cin >> R >> C;

    vector<vector<char> > board; 
    board.resize(R, vector<char>(C,false)); 

    for(int i = 0; i<R; i++){
      for(int k = 0; k<C; k++){
        cin >> board[i][k];
      }
    }


    vector<vector<bool>> visited;
    visited.resize(R, vector<bool>(C, false)) ;

    vector<vector<int>> dist;
    dist.resize(R, vector<int>(C, INF)); 

    bfs(board,visited,dist); 
    int out = dist[R - 1][C - 1]; 
    if(out == INF || board[R - 1][C - 1] == '*'){
      cout << -1 << endl;
    }
    else{
      cout << dist[R - 1][C - 1] << endl;
    }
  }
}
