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
typedef unsigned long long ll;

int N; 

int main()
{
  ll max = 1e5 + 9; 
  bool sieve[max]; 
  fill(sieve, sieve + max, true); 

  for(ll i = 2; i<max; i++){
    for(ll k = i * 2; k<max; k += i){
      sieve[k] = false; 
    }
  }
  sieve[1] = false; 
  sieve[0] = false; 

  vector<ll> primes; 

  for(ll i = 0; i<max; i++){
    if(sieve[i]){
      primes.push_back(i); 
    }
  }

  cin >> N; 
  while(N--){
    ll K; 
    cin >> K; 
    vector<ll> divisors; 
    for(ll i = 0; i<primes.size(); i++){
      if(K % primes[i] == 0){
        K /= primes[i]; 
        cout << primes[i] << " "; 
        i = -1;  
      }
    }
    if(K != 1)
        cout << K;
    cout << endl; 
  }
}
