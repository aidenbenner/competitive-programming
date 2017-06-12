#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const ull MOD = 1000000007;


inline ull mul_mod(ull a, ull e, ull m){
  return a * e % m;

  /**
  ll x = 0, y = a % m; 
  for(; e>0; e  >>= 1){
    if(e & 1) x = (x + y) % m; 
    y = (y << 1) % m; 
  }
  return x % m; **/
}

inline ull mod_exp(ull a, ull b, ull m){
  ull x = 1; ull y = a; 
  for(; b > 0; b >>=1) {
    if(b & 1) x = mul_mod(x,y,m); 
    y = mul_mod(y,y,m);
  }
  return x % m;
}

ull binexp(ull a, ull b, ull m){
  if(b == 0) return 1;
  if(b == 1) return a;
  if(b % 2 == 1){
    return (a * binexp(a, b - 1, m)) % m; 
  }
  return (binexp(a * a,b / 2, m)) % m; 
}

ull towerColoring(int n){
  ull a = mod_exp(3, n, MOD - 1); 
  return mod_exp(3, a, MOD); 
}

int main() {
    int n;
    cin >> n;
    ull result = towerColoring(n);
    cout << result << endl;
    return 0;
}
