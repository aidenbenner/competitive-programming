#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define INF 1e9 
using namespace std; 

int N; 
vector<int> heights; 
unordered_map<int,int> rem; 

int recur(int n) {
  if(n < 0){
    return 0; 
  }
  
  int check = heights[n] - 1; 

  auto itr = rem.find(check); 
  auto curr = rem.find(heights[n]); 

  if(curr == rem.end())
    rem.insert(make_pair(heights[n],1)); 
  else
    curr->second++; 


  if(itr == rem.end())
    return 1 + recur(n - 1); 
  if(itr->second <= 0){
    itr->second = 0;
    return 1 + recur(n - 1); 
  }

  itr->second--; 

  return recur(n - 1); 
}

int main(){
  cin >> N; 
  
  heights.resize(N); 
  for(int i = 0; i<N; i++){
    cin >> heights[i]; 
  }

  cout << recur(N-1); 
}


