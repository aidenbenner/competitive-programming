#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define INF 1e9
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef pair<int,int> IPair;
typedef unsigned long long ull;
typedef long long ll;

int N; 

/**
struct state{
  int n;
  int d;
  vector<bool> visited;

  bool operator==(const state &other) const
  { return (n == other.n && d == other.d && visited == other.visited); 
  }


};**/ 

typedef pair<int, pair<int, vector<bool>> > state;
unordered_map<pair<int, pair<int, vector<bool>>>,int> Memo;

int final_dist = 0;
int recurse(int n, int dist, vector<IPair> & neighbours, vector<bool>& visited)
{
  if(n >= neighbours.size()) return 0; 
  if(n < 0)return 0;

  state sta = make_pair(n,make_pair(dist,visited));
  auto itr = Memo.find(sta);
  if(itr != Memo.end()){
    return *itr.second;
  }

  int out = 0; 
  visited[n] = true;

  int size = neighbours.size(); 

  dist += neighbours[n].second;
  int curr_dist = neighbours[n].first; 
  
  int upper = n+1; 
  bool uphit = false; 
  bool lowhit= false; 
  while( upper < size && visited[upper] ){
    upper++; 
  }
  if(upper != size){
    int top_dist = neighbours[upper].first;
    int delta = abs(curr_dist - top_dist); 
    if(dist - delta >= 0){
      uphit = true;
      out = max(out, delta + recurse(upper, dist - delta, neighbours, visited));
    }
  }

  int lower = n-1; 
  while(lower >= 0 && visited[lower] ){
    lower--; 
  }
  if(lower != -1){ 
    int bot_dist = neighbours[lower].first;
    int delta = abs(curr_dist - bot_dist); 
    if(dist - delta >= 0){
      lowhit = true;
      out = max(out,delta + recurse(lower, dist - delta, neighbours, visited));
    }
  }

  visited[n] = false;
  if(!lowhit && !uphit){
    map.insert(sta,out + dist);
    return out + dist;
  }

  map.insert(sta,out);
  return out; 
}



int main()
{
  cin >> N;

  vector<IPair> nei; 
  nei.resize(N);



  for(int i = 0; i<N; i++){
    int x,d;
    cin >> x >> d;
    nei[i] = make_pair(x,d); 
  }

  sort(nei.begin(), nei.end() ); 

  int starting = 0;
  for(int i = 0; i<nei.size(); i++){
    if(nei[i].first == 0){
      starting = i;
      break;
    }
  }

  vector<bool> visited;
  visited.resize(N);
  fill(visited.begin(), visited.end(), false); 

  cout << recurse(starting,0,nei,visited) + final_dist << endl;
}
