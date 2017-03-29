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

map<long,long> mp;


int close2(int v){
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v++;
  return v;
}


long  get_dist(long n){
  if(mp.find(n) != mp.end()) return mp[n]; 
  //cout << "n " << n << endl
  if(n < 0) n = -n;
  if(n == 0) return 0; 
  long lr = close2(n);
  long  out = 1 + get_dist(n - close2(n));
  mp.insert(make_pair(n, out));
  return out; 
}


int other(long n){
  if(n == 0) return 0; 
  if(n == 1) return 1;


  


  if(n & 1){
    //int diff1 = close2(n) - n;
    //int diff2 = n - (close2(n) >> 1);

    //if(diff1 < diff2){
      //return 2 + other((n+1)/2); 
    //}
    //return 2 + other((n-1)/2); 

    return 2 + min(other((1+n)/2), other((n-1)/2)); 
  }
  return 1 + other(n/2); 
}


int get(int n)
{
    int x = log2(n); 
    int zero = x - __builtin_popcount(n) + 1; 
    int pop = __builtin_popcount(n);
    int out;
    if(zero < pop){
      x += 2; 
      out = (x + min(zero));
    }
    else{
      out = x + pop; 
    }
    return out;
}

int main()
{
  cin >> N;

  for(int i = 0; i<100; i++){
    int x = log2(i); 
    
    //cout << i << "  " << get(i) << endl;
    if(get(i) != other(i)) {
      cout << i << " " << get(i) << "  " << other(i) << " ";
    for(int k=7; k>=0; k--)
{
   cout<<((i>>k)&1);
}
  cout << endl;
      
    }
  }

  while(N--){
    long n; 
    cin >> n;
    if(n == 0) { cout << 0 << endl; continue; } 
    if(n == 3) { cout << 3 << endl; continue; }
    //long lr = close2(n); 
    //long  x = 1 + log2(lr); 
    //cout << "   " << x << "  " << log2(lr) << endl;
    //cout << (x + get_dist(n - close2(n))) << endl;

    cout << get(n) << endl;
  }
}
