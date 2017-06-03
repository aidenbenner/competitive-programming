#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define INF 1e9
#define EPS 1e-13
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int G,P; 
int main()
{
  cin >> G >> P;

  int planes[P];
  for(int i = 0; i<P; i++){
    cin >> planes[i]; 
  }

  set<int> gates; 
  for(int i = 0; i<G; i++){
    gates.insert(-i); 
  }

  int filled = 0; 
  for(int i = 0; i<P; i++){
    auto up = gates.lower_bound(-planes[i] + 1); 
    if(up == gates.end()){
      break;
    }
    filled++; 
    gates.erase(*up);
  }
  cout << filled;
}
