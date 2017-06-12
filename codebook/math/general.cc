#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cstring>
#include <cstdlib>

#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define MOD 1000000007

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;


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

ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b, a % b); 
}

bool prob_prime(ll n, int itrs){
  for(int i = 0; i<itrs; i++){
    ll x = ((ll)rand() % (n-2)) + 1;
    if(mod_exp(x,n-1,n) != 1){
      return false; 
    }
  }
  return true;
}

bool* sieve(int n) {
  bool * ret = (bool*)malloc(sizeof(bool) * n); 
  memset(ret, 1, sizeof(bool) * n); 
  for(int i = 0; i<n; i++){
    for(int k = i * 2; k<n; k += i)
      ret[k] = false; 
  }
  return ret;
}

int main()
{
  srand(time(NULL)); 
  cout << mod_exp(3,24, MOD) << endl;
  cout << mod_exp(4,300, MOD) << endl;
  cout << gcd(5,15) << endl;
  cout << gcd(41,MOD) << endl;
  cout << gcd(MOD,41) << endl;
  cout << gcd(2 * 4 * 5,8 * 41) << endl;
  assert(prob_prime(41, 5)); 
  assert(prob_prime(MOD, 5)); 
  assert(!prob_prime(MOD + 1, 5)); 
}
