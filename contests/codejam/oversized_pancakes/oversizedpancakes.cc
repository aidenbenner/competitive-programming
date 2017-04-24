#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>

#define INF 1e9
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;


int solve(vector<bool> &arr, int k){
  int tot = 0; 
  for(int i = 0; i<arr.size() - k + 1; i++){
    if(arr[i] == 0){
      for(int j = 0; j<k; j++){
        if(i + j >= arr.size()) continue;
        arr[i + j] = !arr[i + j]; 
      }
      tot++; 
    }
  }

  for(int i = 0; i<arr.size(); i++){
    if(arr[i] == false){
      return -1; 
    }
  }
  return tot; 
}

int main()
{
  int N;
  cin >> N;
  string str;
  for(int i = 0; i<N; i++)
  {
    int k;
    cin >> str;
    cin >> k;
    vector<bool> b; 
    b.resize(str.size()); 
    for(int j = 0; j<str.size(); j++){
      b[j] = (str[j] == '+');
    }
    int out = solve(b, k); 
    if(out == -1){
      printf("Case #%d: IMPOSSIBLE\n", i + 1);
      continue;
    }
    printf("Case #%d: %d\n", i + 1, out); 
  }
}
