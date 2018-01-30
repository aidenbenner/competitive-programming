#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define INF 1e9
#define EPS 1e-9
#define lim 1000001

using namespace std;

typedef vector<vector<pair<int,int> > > Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

int N; 

ll mod_exp(ll a, ll b, ll m) {
  if(b == 0) return 1; 
  if(b == 1) return a % m; 
  a %= m;
  if(b & 1) {
    return (a * mod_exp(a, b - 1, m)) % m; 
  }
  return (mod_exp(a * a, b >> 1, m) % m); 
}

// assumes a is coprime to m
ll mod_inv(ll a, ll m){
  return mod_exp(a, m - 2, m); 
}

ll mod_div(ll a, ll b, ll m){
  a %= m; 
  b %= m; 
  return (a * mod_inv(b,m)) % m; 
}

ll dp[lim];

ll fact(int n){
    if(dp[n] != -1) return dp[n];
    if(n == 0) return 1;
    return dp[n] = n * fact(n - 1) % MOD;
}


ll perm(ll n, ll k){
    if(n == 0) return 1;
    //if(dpp[n][k] != -1) return dpp[n][k];
    return mod_div(fact((ll)n),  fact((ll)n - (ll)k), MOD);
}

int main()
{
  scanf("%d", &N); 
  fill(dp, dp + lim, -1); 
  for(int T = 1; T<=N; T++){
      ll x;
      scanf("%lld", &x); 
      ll sum = 0; 
      for(ll i = 2; i<=x; i++){
            sum += mod_div(perm(x, i),2, MOD);
      }
      sum -= mod_div((ll)x * (x - 1), 2, MOD);
      if(sum < 0) sum = 0;
      printf("%llu\n", sum % MOD);
  }
}
