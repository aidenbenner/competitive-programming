#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define INF 1e9
#define EPS 1e-10
#define pb push_back
#define MOD 1000000007

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 

typedef vector< vector<ll>> Mat; 

Mat matrix; 


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


inline void rowMult(int row, double c){
  for(int i = 0; i<matrix[row].size(); i++ ){
    matrix[row][i] = matrix[row][i] * c; 
  }
}

//adds rowB * c = rowA
inline void addMult(int rowA,int rowB, ll c){
  for(int i = 0; i<matrix[rowA].size(); i++){
    matrix[rowA][i] = matrix[rowA][i] + mul_mod(c , matrix[rowB][i], MOD); 
    matrix[rowA][i] %= MOD;
  }
}

inline void interchange(int rowA,int rowB){
  for(int i = 0; i<matrix[rowA].size(); i++){
    double hold = matrix[rowA][i];
    matrix[rowA][i] = matrix[rowB][i];
    matrix[rowB][i] = hold;
  }
}

ll gaussianElim(bool findDet) {
  int cols = matrix[0].size();
  int rows = matrix.size();
  int pivotInd = 0; 
  ll det = 1; 

  for(int i = 0; i<cols; i++){
    for(int k = pivotInd; k<rows; k++){
      if(fabs(matrix[k][i]) > EPS){
        if(pivotInd != k){ 
          interchange(pivotInd, k);
          det = det * -1;
        }
        
        ll leadingVal = matrix[pivotInd][i];

        ll pivInv = mod_exp(matrix[pivotInd][i], MOD - 2, MOD) ; for(int z = pivotInd + 1; z<rows; z++){
          if(z == pivotInd) continue;
          leadingVal = (-1 * mul_mod(matrix[z][i], pivInv, MOD) + MOD);
          if(leadingVal != 0 ){
            addMult(z,pivotInd,leadingVal);
          }  
        }
        pivotInd++;
        break;
      }
    }
  }
  for(int i = 0; i<cols; i++){
    if(fabs(matrix[i][i]) < EPS) return 0; 
    det = det * matrix[i][i] % MOD;
    det = det % MOD;
  }
  return (det + MOD) % MOD;
}



int main()
{
  scanf("%d", &N); 

  matrix.resize(N); 
  for(int i = 0; i<N; i++){
    matrix[i].resize(N); 
    for(int k = 0; k<N; k++){
      scanf("%lld", &matrix[i][k]); 
      if(matrix[i][k] < 0) matrix[i][k] += MOD;
    }
  }

  long long det = gaussianElim(true);
  if(det < 0){
    cout << MOD - det  << endl;
  }
  else{
    cout << det  << endl;
  }
}
