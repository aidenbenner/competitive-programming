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

int N; 

void solve(vector<ull>& v) {

  bool sorted = true; 
  int last = v[v.size() - 1];
  for(int i = v.size() - 1; i >= 0; i--){
    int curr = v[i]; 
    if(curr < last){
      sorted = false; 
      v[i + 1]--; 
      for(int k = i; k >= 0; k--){
        v[k] = 9; 
      }
      break;
    }
    last = curr;
  }

  if(sorted){
    return;
  }

  solve(v);
}


int main()
{
  cin >> N;
  for(int t = 0; t<N; t++){

    ull s;
    cin >> s;
    
    vector<ull> v; 
    while(s > 0){
      v.push_back(s % 10); 
      s /= 10; 
    }

    solve(v);  

    string out = ""; 

    for(int i = v.size() - 1; i >= 0; i--){
      if(v[i] <= 0){
        continue;
      }

      for(; i >= 0; i--){
        out += v[i] + '0'; 
      }

      break;
    }



    printf("Case #%d: %s\n", t + 1, out.c_str()); 

  }
}

