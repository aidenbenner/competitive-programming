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


const int BIT_SIZE = 1000005; 
ll bit[BIT_SIZE]; 

ll sum(ll n)
{
  ll sum = 0;
  while(n > 0){
    sum += bit[n];
    //clear right bit
    n -= (n & -n); 
  }
  return sum;
}

void update(int k, int v)
{
  for(; k<BIT_SIZE; k+= (k & -k)) bit[k] += v; 
}

int main()
{
  fill(bit,bit + BIT_SIZE,0); 
  ll t;
  scanf("%lld", &t); 
  ll vals[t]; 
  ll sorted[t]; 
  for(ll i = 0; i<t; i++){
    scanf("%lld", &vals[i]); 
    vals[i]++; 
    sorted[i] = vals[i];
  }

  sort(sorted, sorted + t);
  map<ll,int> mp;

  for(ll i = 0; i<t; i++){
    mp[sorted[i]] = i + 1;
  }
  
  double s = 0; 
  for(ll i = 0; i<t; ++i){
    s += i - sum(mp[vals[i]]) + 1;
    update(mp[vals[i]],1); 
  }

  printf("%.2lf\n", (double)s / t);

}

