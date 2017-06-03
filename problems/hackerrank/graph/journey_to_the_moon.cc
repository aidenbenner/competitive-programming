#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

multiset<int> visited;

void DFS(vector<vector<int> >&  pairs, int source, vector<int>& countries){
  if(visited.count(source) != 0){
    return;
  }
  visited.insert(source); 

  queue<int> next; 
  next.push(source); 
  countries.push_back(1); 

  while(!next.empty()){
    int curr = next.front(); 
    next.pop(); 
    for(int i = 0; i<pairs[curr].size(); i++){
      if(visited.count(pairs[curr][i]) == 0){
        visited.insert(pairs[curr][i]); 
        countries[countries.size() - 1]++;
        next.push(pairs[curr][i]);
      }
    }
  }
}

int main()
{ 
  int N, I;
  cin >> N >> I;
  vector<vector<int> > pairs(N + 1);
  for (int i = 0; i < I; ++i) {
    int a, b;
    cin >> a >> b;
    pairs[a].push_back(b);
    pairs[b].push_back(a);
  }

  long long result = 0;
  vector<int> countries;

  for(int i = 0; i<N; i++){
    DFS(pairs,i,countries); 
  }

  long long sum = 0;
  long long dp[countries.size()]; 
  dp[countries.size() - 1] = countries[countries.size() - 1];
  for(int i = countries.size() - 2; i>=0; i--){
    dp[i] = dp[i + 1] + countries[i];
  }
  for(int i = 0; i<countries.size() - 1; i++){
    result += countries[i] * dp[i + 1]; 
  }

  cout << result << endl;
  return 0;
}
