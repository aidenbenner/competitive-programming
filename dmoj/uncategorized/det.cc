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


ll mul_mod(ll a, ll e, ll m){
  ll x = 0, y = a % m; 
  for(; e>0; e  >>= 1){
    if(e & 1) x = (x + y) % m; 
    y = (y << 1) % m; 
  }
  return x % m; 
}

ll mod_exp(ll a, ll b, ll m){
  ll x = 1; ll y = a; 
  for(; b > 0; b >>=1) {
    if(b & 1) x = mul_mod(x,y,m); 
    y = mul_mod(y,y,m);
  }
  return x % m;
}

ll mod_div(ll a, ll b, ll m)
{
  return mul_mod(a, mod_exp(b,m-2,m), m);   
}



void rowMult(Mat &matrix, int row, double c){
  for(int i = 0; i<matrix[row].size(); i++ ){
    matrix[row][i] = matrix[row][i] * c; 
  }
}

//adds rowB * c = rowA
void addMult(Mat &matrix, int rowA,int rowB, ll c){
  for(int i = 0; i<matrix[rowA].size(); i++){
    matrix[rowA][i] = (matrix[rowA][i] + mul_mod(c , matrix[rowB][i], MOD)) + MOD; 
    matrix[rowA][i] %= MOD;
  }
}

void interchange(Mat &matrix, int rowA,int rowB){
  for(int i = 0; i<matrix[rowA].size(); i++){
    double hold = matrix[rowA][i];
    matrix[rowA][i] = matrix[rowB][i];
    matrix[rowB][i] = hold;
  }
}

ll gaussianElim(Mat &matrix, bool findDet) {
  int cols = matrix[0].size();
  int rows = matrix.size();
  int pivotInd = 0; 
  ll det = 1; 

  for(int i = 0; i<cols; i++){
    for(int k = pivotInd; k<rows; k++){
      if(fabs(matrix[k][i]) > EPS){
        if(pivotInd != k){ 
          interchange(matrix, pivotInd, k);
          det = det * -1;
        }
        
        ll leadingVal = (matrix[pivotInd][i]) % MOD;

        ll pivInv = mod_exp(matrix[pivotInd][i], MOD - 2, MOD) ;
        for(int z = pivotInd + 1; z<rows; z++){
          leadingVal = mul_mod(matrix[z][i], pivInv, MOD);
          addMult(matrix,z,pivotInd,-leadingVal);
        }
        pivotInd++;
        break;
      }
    }
  }
  for(int i = 0; i<cols; i++){
    if(fabs(matrix[i][i]) < EPS) return 0; 
    det = det * matrix[i][i] % MOD;
  }
  return (det + MOD) % MOD;
}



int main()
{
  scanf("%d", &N); 

  Mat arr; 
  arr.resize(N); 
  for(int i = 0; i<N; i++){
    arr[i].resize(N); 
    for(int k = 0; k<N; k++){
      scanf("%lld", &arr[i][k]); 
      if(arr[i][k] < 0) arr[i][k] += MOD;
    }
  }

  long long det = gaussianElim(arr, true);
  if(det < 0){
    cout << MOD - det  << endl;
  }
  else{
    A
    cout << det  << endl;
  }
}
