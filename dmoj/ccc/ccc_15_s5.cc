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
#define MOD 1000000007

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 
int pies[3001]; 
int MEMO[3001]; 

int recurse(int n, int l, int r)
{
  if(n < 0) return 0; 
  if(MEMO[n] != -1)
    return MEMO[n]; 

  int out = 0;
  out = max(out, pies[n] + recurse(n - 2));
  out = max(out, recurse(n - 1));
  return MEMO[n] = out;
}

int main()
{
  cin >> N; 

  for(int i = 0; i<N; i++){
    cin >> pies[i];
  }

  fill(MEMO, MEMO + N, -1); 

  int M; 
  cin >> M; 
  int extra[M]; 
  for(int i = 0; i<M; i++){
    cin >> extra[i];
  }


  sort(extra, extra + M); 
  int sum = 0; 
  int min_big = extra[M/2];
  for(int i = M/2 + 1; i<M; i++){
    sum += extra[i];
  }

  int out = recurse(N - 1); 
  out = max(out, min_big + recurse(N - 2)); 

  cout << sum << endl;
  cout << (out + sum) << endl;
}
