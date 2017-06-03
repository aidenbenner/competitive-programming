#include <bits/stdc++.h>

#define INF 1e9 
typedef long long ll;

using namespace std;
typedef vector<int> VI; 
int N, Q;

void polyMult(ll  a[], int an, ll  b[], int bn, ll  out[], int on){
  for(int i = 0; i < an; i++){
    out[i] = 0; 
  }

  for(int i = 0; i<an; i++){
    for(int k = 0; k<bn; k++){
      if(i + k >= an){
        continue;
      }
      out[i + k] += a[i] * b[k]; 
    }
  }

  for(int i = 0; i<an; i++){
    a[i] = out[i]; 
  }
}

ll fx(ll  poly[], int n, ll  x){
  ll sum = 0; 
  for(int i = n - 1; i>=1 ; i--){
    sum += poly[i];
    sum *= x; 
//    cout << poly[i]  << "  " <<  sum << endl; 
  }
  sum += poly[0];
  return sum; 
} 

ll solve(ll  poly[], int n, ll  x, ll  y){
  return (ll)y / fx(poly,n,x); 
}


int main(){
  cin >> Q;

  while(Q--){
    cin >> N;

    ll  tmp[N + 1]; 
    ll  curr[N + 1]; 
    ll  next[N + 1]; 

    for(int i = 0; i<N + 1; i++){
      curr[i] = 0; 
      next[i] = 0; 
      tmp[i] = 0; 
    }

    next[1] = 1; 
    curr[1] = 1; 
    cin >> curr[0]; 
    curr[0] *= -1;

    int deg = 1; 
    for(int i = 0; i<N - 1; i++){
      cin >> next[0]; 
      next[0] *= -1;

      /**
      for(int i  =  0; i<deg + 1; i++){
        cout << curr[i] << "  ";
      }
        cout << endl;
      for(int i  =  0; i<deg + 1; i++){
        cout << next[i] << "  "; 
      }
        cout << endl;**/
      
      polyMult(curr,N+1,next,2,tmp,N+1); 

      /**
      for(int i  =  0; i<deg + 2; i++){
        cout << curr[i] << "  "; 
      }
        cout << endl;**/ 

      deg++; 
    }
    ll  x ,y; 
    cin >> x >> y;

    
    ll a = solve(curr,N + 1, x,y); 

    for(int i = 0; i< N + 1; i++){
      cout << a * curr[N - i]  << " ";
    }
    cout << endl;
  }
}
