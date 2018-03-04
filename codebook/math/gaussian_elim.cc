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

ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b,a%b); 
}

ll lcm(ll a, ll b){
  return a / gcd(a,b) * b; 
}

typedef vector< vector<ll>> Mat; 

void rowMult(Mat &matrix, int row, ll c){
  for(int i = 0; i<matrix[row].size(); i++ ){
    matrix[row][i] = matrix[row][i] * c; 
  }
}

//adds rowB * c = rowA
void addMult(Mat &matrix, int rowA,int rowB, ll c){
  for(int i = 0; i<matrix[rowA].size(); i++){
    matrix[rowA][i] = matrix[rowA][i] + c * matrix[rowB][i];
  }
}

void interchange(Mat &matrix, int rowA,int rowB){
  for(int i = 0; i<matrix[rowA].size(); i++){
    double hold = matrix[rowA][i];
    matrix[rowA][i] = matrix[rowB][i];
    matrix[rowB][i] = hold;
  }
}


int gaussianElim(Mat &matrix, bool findDet) {
  int cols = matrix[0].size();
  int rows = matrix.size();
  int pivotInd = 0; 
  ll det = 1; 
  ll denom = 1; 

  for(int i = 0; i<cols; i++){
    //reduce each column so we only have 1 as a pivot and all zeroes
    for(int  k = pivotInd; k<rows; k++){
      if(matrix[k][i] != 0){
        //we found a non zero value in this column.
        //swap it to the row of the pivot we're working on 
        if(pivotInd != k){ 
          interchange(matrix, pivotInd, k);
          //if(findInverse){
            //interchange(identity, pivotInd, k);
          //}
          det = det * -1;
        }

        
        //for(int i = 0; i<N; i++){
          //for(int k = 0; k<N; k++){
            //printf("%3lf ",  matrix[i][k])  ;
          //}
          //cout << endl;
        //}
        //cout << leadingVal << endl;
        //if(findInverse){
          //rowMult(identity, pivotInd, 1/leadingVal);
        //}
        

        ll leadingVal = matrix[pivotInd][i];
        rowMult(matrix, pivotInd, 1.0/leadingVal);
        det = llround(det * leadingVal);
        det = (det) % MOD; 

        for(int z = pivotInd; z<rows; z++){
          if(z == pivotInd) continue;
          leadingVal = matrix[z][i];
          if(leadingVal!=0){
            addMult(matrix,z,pivotInd,-leadingVal);
          }  
        }
        pivotInd++;
        break;
      }
    }
  }
  for(int i = 0; i<cols; i++){
    det = llround(det * (matrix[i][i]));
    det = (det) % MOD;
  }
  return (det + MOD) % MOD;
}



int main()
{
  cin >> N;

  Mat arr; 
  arr.resize(N); 
  for(int i = 0; i<N; i++){
    arr[i].resize(N); 
    for(int k = 0; k<N; k++){
      cin >> arr[i][k]; 
      cout << arr[i][k] << " ";
    }
    cout << endl;
  }

  long long det = gaussianElim(arr, true);
  if(det < 0){
    cout << MOD - det  << endl;
  }
  else{
    cout << det  << endl;
  }
}

