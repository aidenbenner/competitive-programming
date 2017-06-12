#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int f (int x, int y, int a, int b){
  return x * x + y * y - x * a - y * b;
}

ll countSolutions(ll a, ll b, ll c, ll d){
  ll solns = 0; 
  for(ll x = 1; x<=c; x++){
    ll c = x * x - x * a; 
    ll rad = b * b - 4 * c; 
    if(rad < 0) continue;
    ll irad = sqrt(rad); 
    bool perf = irad == sqrt(rad); 
    if(perf){
      
      ll y0 = (b + round(sqrt(rad)));
      ll y1 = (b - round(sqrt(rad))); 

      if((y0 > 0 && (y0 / 2) <= d) && (y0 % 2 == 0)){ solns++; }
      if((y1 > 0 && (y1 / 2) <= d) && y1 != y0 && (y1 % 2 == 0)){ solns++; }
    }
  }
  return solns;
}

int main() {
    ll q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        ll a;
        ll b;
        ll c;
        ll d;
        cin >> a >> b >> c >> d;
        ll result = countSolutions(a, b, c, d);
        cout << result << endl;
    }
    return 0;
}
