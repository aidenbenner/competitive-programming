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

int NA, KA; 

int MEMO[31][901];


ll fact(int i){
  ll out = 1; 
  while(i >= 1){
    out *= i;
    i--;
  }
  return out;
}

ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b, a%b);
}

ll choose(int left, int right)
{
  if(left == 0) return 1;
  if(right == 0) return 1;

  int N = left + right;

  ll out = 1;
  while(N > max(left,right)){
    out *= N; 
    N--; 
  }
  return (out / fact(min(left,right)));
}

ll permute(int N, int K)
{
  if(N == 1){
    if(K == 1)
    return 1; 
    return 0;
  }
  if(N == 0){
    if(K == 0)
    return 1;
    return 0;
  }
  //if(N == 2){
    //if(K == 3){
      //return 2;
    //}
    //return 0;
  //}

  if(MEMO[N][K] != -1){
    return MEMO[N][K]; 
  }

  ll out = 0; 
  K -= N;
  if(K <= 0){
    return 0; 
  }
  for(int j = 0; j<=N - 1; j++){
    for(int i = 0; i<=K; i++){
      int left = j; 
      int right = N-j-1;
      out += permute(N-j-1, i)  * permute(j, K-i) * (choose(left , right)); 
      out %= MOD;
    }
  }
  return MEMO[N][K + N] = out % MOD;
}

int main()
{
  cin >> NA;
  cin >> KA; 

  for(int i = 0; i<31; i++){
    for(int k = 0; k<901; k++){
      MEMO[i][k] = -1;
    }
  }

  cout << permute(NA,KA) << endl;
}
