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

ll N, K; 
int main()
{
  std::ios_base::sync_with_stdio(false);
  cin >> N;
  cin >> K;

  ll keys[N]; 
  ll doors[N]; 
  ll z[N];

  for(ll i = 0; i<N; i++){
    cin >> z[i]; 
    z[i] -= 1; 
    doors[i] = 0; 
  }

  for(ll i = 0; i<N; i++){
    keys[z[i]] = i;
  }

  ll wrong = 0; 
  doors[0] = (keys[0] - keys[N - 1] + N)  % N; 
  for(ll i = 1; i<N; i++){
    doors[i] = (((keys[i] - keys[i - 1]) + N) % N);
    wrong += doors[i]; 
  }
  wrong += doors[0]; 


  ll x = (wrong) * (K / N); 
  x -= (doors[0] - keys[0]); 
  for(ll i = 0; i < K % N; i++){
    x += doors[i]; 
  }
  cout << x << endl;
}
