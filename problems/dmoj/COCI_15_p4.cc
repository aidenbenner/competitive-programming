#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set> 

#define INF 1e9 

using namespace std; 

struct Rook {
  int row;
  int col;
  int p; 
}


int main(){
  int N, K, P; 
  cin >> N >> K >> P; 
  
  Rook pieces[K]; 

  for(int i = 0; i<K; i++){
    Rook r; 
    cin >> r.row >> r.col>> r.p;
    pieces[i] = r; 
  }
  //check conflict for each row
  //first sort by row 

  


  for(int i = 0; i<P; i++){

  }
}


