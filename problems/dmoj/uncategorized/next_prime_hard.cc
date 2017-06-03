#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cstdlib>

#define INF 1e9
#define EPS 1e-13
#define pb push_back
#define MOD 1000000007

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ll;

bool sieve[5000]; 

void gen(){
  for(int i = 1; i*i<5000; i++){
    for(int k = i + i; k < 5000; k += i){
      sieve[k] = false; 
    }
  }
}

//ancient egyptian magic
ll mul_mod(ll a, ll e, ll m){
  ll x = 0, y = a % m; 
  for(; e>0; e  >>= 1){
    if(e & 1) x = (x + y) % m; 
    y = (y << 1) % m; 
  }
  return x % m; 
}

//binary exp w/ egyptian magic
ll mod_exp(ll a, ll b, ll m){
  ll x = 1; ll y = a; 
  for(; b > 0; b >>=1) {
    //b & 1 == b % 2 == 1 
    if(b & 1) x = mul_mod(x,y,m); 
    y = mul_mod(y,y,m);
  }
  return x % m;
}

bool prob_prime(ll n){
  for(int i = 0; i<2; i++){
    ll x = ((ll)rand() % (n-2)) + 1;
    //cout << x << endl;
    if(mod_exp(x,n-1,n) != 1){
      return false; 
    }
  }

  return true;
}

ll N; 
int main()
{
  srand (time(NULL)); cin >> N; 
  if(N == 1){ cout << 2 << endl; return 0; } 



  if(N < 4500){
    fill(sieve, sieve + 5000, true); 
    gen(); 
    sieve[1] = false; 
    sieve[0] = false;

    for(int i = N; i<5000; i++){ if(sieve[i]){ cout << i << endl; return 0; }
    }
  }

  if(N == 2){ cout << 2 << endl; return 0; } 
  if(N % 2 == 0){
    N++; 
  }

  while(!prob_prime(N)){
//    cout << N << endl;
    N += 2;
  }
  cout << N << endl;
}
