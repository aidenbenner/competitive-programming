#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;


bool board[25][25]; 
bool visited[25][25]; 

int BFS(int x, int y){
  if(x < 0) return 0; 
  if(y < 0) return 0; 
  if(y >= 25) return 0; 
  if(x >= 25) return 0; 
  if(!board[x][y]) return 0; 
  if(visited[x][y]) return 0; 
  visited[x][y] = true;
  int out = 1; 
  out += BFS(x + 1, y); 
  out += BFS(x - 1, y); 
  out += BFS(x, y + 1); 
  out += BFS(x, y - 1); 
  return out; 
}


int main()
{
  int N, R,C; 

  cin >> N >> R >> C; 
  memset(board, false, sizeof(board)); 
  memset(visited, false, sizeof(visited)); 

  for(int i = 0; i<R; i++){
    for(int k = 0; k<C; k++){
      char next;
      cin >> next;
      board[i][k] = next == '.'; 
    }
  }

  vector<int> room_sizes; 
  for(int i = 0; i<R; i++){
    for(int k = 0; k<C; k++){
      if(board[i][k]){
        if(!visited[i][k]){
          room_sizes.push_back(BFS(i,k));  
        }
      }
    }
  }
  sort(room_sizes.begin(), room_sizes.end()); 

  for(int i = 0; i<room_sizes.size(); i++){
    int next = room_sizes[room_sizes.size() - 1 - i];
    if(N < next){
      if(i == 1){
        printf("%d room, %d square metre(s) left over", i, N); 
        return 0; 
      }
      printf("%d rooms, %d square metre(s) left over", i, N); 
      return 0; 
    }
    N -= next;
  }
  if(room_sizes.size() == 1){
    printf("%d room, %d square metre(s) left over", (int)room_sizes.size(), N); 
    return 0; 
  }
  printf("%d rooms, %d square metre(s) left over", (int)room_sizes.size(), N); 
}
