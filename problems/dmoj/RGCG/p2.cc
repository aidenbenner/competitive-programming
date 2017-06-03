#include <bits/stdc++.h>

#define INF 1e9 

using namespace std;
typedef vector<int> VI; 
typedef unsigned long long ll;

ll N, M, Q;

int main(){
  cin >> N >> M >> Q;

  map<ll,ll> vals; 

  ll cubes[N]; 
  ll left[N];
  ll right[N + 1];
  ll sum = 0;

  right[N] = 0;

  for(ll i = 0; i<N; i++){
    cin >> cubes[i]; 
    sum += cubes[i]; 
    left[i] = sum; 
    vals.insert(make_pair(cubes[i], i)); 
  }

  right[0] = sum;
  for(ll i = 1; i<N; i++){
    right[i] = sum - left[i-1];
  }

  for(ll i = 0; i<Q; i++){
    ll A,B;
    cin >> A >> B;
    A = vals[A]; 
    B = vals[B]; 

    ll val; 
    if(A - 1 < 0){
      val = sum - (right[B + 1]);  
    }
    else{
      val = sum - (right[B + 1] + left[A - 1]);  
    }

    val /= 2;
    if(val >= M){
      cout << "Enough" << endl;
    }
    else{
      cout << "Not enough" << endl;
    }
  }

}
