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
int A[2001]; 
int B[4004]; 

int main()
{
  cin >> N;

  fill(A, A+2001, 0); 
  fill(B, B+4004, 0); 

  int arr[N]; 
  int combs[N]; 
  for(int i = 0; i<N; i++){
    int k; 
    cin >> k; 
    A[k]++; 
  }

  
  for(int i = 0; i<2001; i++){
    for(int k = i + 1; k<2001; k++){
      if(A[k] == 0 || A[i] ==0) continue;
      cout << " one way to make " << (i + k) << "  " << i << "  " << k << endl;
      B[i + k] += 1; 
    }
  }

  int maxInd = 1; 
  for(int i = 4003; i>=1; i--){
    if(B[i] != 0){
      cout << i << " " << B[i] << endl;
      if(B[maxInd] < B[i]){
        maxInd = i; 
      }
    }
  }


  cout << maxInd << " " << B[maxInd] << endl;
}
