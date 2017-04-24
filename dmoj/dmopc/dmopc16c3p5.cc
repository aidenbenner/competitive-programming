#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;


int memo[N][K]; 

vector<double> recr(int n, vector<int> & a, int k){

  if(memo[n][k] != -1){
    return memo[n][k];
  }

  int rem = a.size() - n;
  if(rem <= 0){
    return memo[n][k] = 0; 
  }

  if(rem == 1){
    return memo[n][k] = a[n]; 
  }

  double op1 = a[n] + a[n + 1]; 
  op1 -= min(a[n], a[n+1]) * 0.5; 
  op1 += recr(n + 2, a, k); 

  if(rem == 2) return op1; 

  double op2 = a[n] + a[n + 1] + a[n+2]; 
  op2 -= min(a[n], min(a[n + 2] , a[n+1])) ;
  op2 += recr(n + 3, a, k); 

  memo[n][0] = 

  return memo[n][k] = min(op1, op2); 
}



int main(){
  int N, K;
  cin >> N >> K; 

  vector<int> a; 
  for(int i = 0; i<N; i++){
    int z; 
    cin >> z; 
    a.push_back(z); 
  }

  printf("%.1lf", recr(0,a,0) );
}
