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

ll MEMO[31][901];
ll FACT[31][31];

inline ll mul_mod(ll a, ll e, ll m){
  return a * e % m;

  /**
  ll x = 0, y = a % m; 
  for(; e>0; e  >>= 1){
    if(e & 1) x = (x + y) % m; 
    y = (y << 1) % m; 
  }
  return x % m; **/
}

inline ll mod_exp(ll a, ll b, ll m){
  ll x = 1; ll y = a; 
  for(; b > 0; b >>=1) {
    if(b & 1) x = mul_mod(x,y,m); 
    y = mul_mod(y,y,m);
  }
  return x % m;
}

inline ll mod_div(ll a, ll b, ll m)
{
  return mul_mod(a, mod_exp(b,m-2,m), m);   
}

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
  if(FACT[left][right] != -1){
    return FACT[left][right]; 
  }
  if(FACT[right][left] != -1){
    return FACT[right][left]; 
  }


  int N = left + right;

  ll out = 1;
  while(N > max(left,right)){
    out *= N; 
    N--; 
  }

  return FACT[right][left] =  (MOD + mod_div(out, fact(min(left,right)), MOD)) % MOD;
}

ll permute(int N, int K)
{
  if(N == 1){
    //cout << "FREE" << endl;
    //cout << N << "  " << K << endl;
    if(K == 1)
    return 1; 
    return 0;
  }
  if(N == 0){
    //cout << "FREE" << endl;
    //cout << N << "  " << K << endl;
    if(K == 0)
    return 1;
    return 0;
  }

  if(MEMO[N][K] != -1){
    return MEMO[N][K]; 
  }

  if(K > N * N)
    return 0;

  ll out = 0; 
  K -= N;
  if(K <= 0){
    return 0; 
  }
  for(int j = 0; j<=N - 1; j++){
    for(int i = N - j - 1; i<=K; i++){
      if(j > K - i) break;
      int left = j; 
      int right = N-j-1;
      out += permute(N-j-1, i)  * permute(j, K-i) * (choose(left , right)); 
    }
  }
  return MEMO[N][K + N] = out % MOD;
}

int main()
{
  cin >> NA;
  cin >> KA; 

  for(int i = 0; i<31; i++){
    for(int k = 0; k<31; k++)
      FACT[i][k] = -1; 
  
  }
  for(int i = 0; i<31; i++){
    for(int k = 0; k<901; k++){
      MEMO[i][k] = -1;
    }
  }

  long out = permute(NA,KA); 
  if(out < 0) out += MOD;
  cout << out << endl;
}

