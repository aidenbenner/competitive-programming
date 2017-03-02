#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

#define INF 1e9
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 

struct VectorHash {
  size_t operator()(const std::vector<int>& v) const {
    std::hash<int> hasher;
    size_t seed = 0;
    for (int i : v) {
      seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
    return seed;
  }
};

bool sorted(vector<int> & a, int n)
{
  for(int i = 0; i<n - 1; i++){
    if(a[i] >= a[i+1]){
      return false;
    }
  }
  return true;
}

bool impossible(vector<int> &a, int n){
  for(int i = 0; i<n; i++){
    if(a[i] == i){
      for(int k = i-1; k>=0; k--){
        if(a[k] > a[i]) {
          return false;
        }
      }
      for(int k = i+1; k<n; k++){
        if(a[k] < a[i]) {
          return false;
        }
      }
    }
  }
}


unordered_set<vector<int>, VectorHash > visited;

vector<int> moves;
bool recurse(vector<int> &a, int n)
{

  auto itr = visited.find(a); 
  if(itr != visited.end()){
    return false;
  }
  visited.insert(a); 

  vector< vector<int> > queue;  
  queue.push_back(a); 
  while(pq.isEmpty()){
    vector<int> curr = pq.front();
    pq.pop(); 

    if(visited[pq])
    
    if(sorted(a,n)){
      return true;
    }

    for(int i = 0; i<n - 1; i++){
      int tmp = a[i + 1];
      a[i + 1] = a[i]; 
      a[i] = tmp;
      if(recurse(a,n)){
        moves.push_back(i);
        return true;
      } 
      tmp = a[i + 1];
      a[i + 1] = a[i]; 
      a[i] = tmp;

    }

}



int main()
{
  cin >> N;
  vector<int> arr;
  arr.resize(N);
  for(int i = 0; i<N; i++){
    cin >> arr[i]; 
  }
  if(!recurse(arr,N)){
    cout << "Give up" << endl;
  }
  else{
    cout << moves.size() << endl;
    for(int i = 0; i<moves.size(); i++){
      cout << moves[ moves.size() - 1 - i] << " " << moves[ moves.size() - 1 - i] + 1<< endl;
    }
  }
}
