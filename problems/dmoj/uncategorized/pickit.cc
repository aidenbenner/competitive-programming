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

int state[201][201]; 
int arr[201]; 

int recr(int bot, int n) {
  if(n < 3){
    return 0;
  }
  if(n == 3){
    return arr[bot + 1] + arr[bot] + arr[bot + 2]; 
  }
  if(state[bot][n] != -1) 
    return state[bot][n]; 


  int max_score = 0; 
  for(int i = 1; i<n - 1; i++){
    int score = 0; 
    int curr_selection = arr[bot + i] + arr[bot + i - 1] + arr[bot+i+1]; 
    score += recr(1, i); 
    score += recr(i + 1, n - i - 1); 
    score += curr_selection;
    max_score = max(max_score, score); 
  }

  return state[bot][n] = max_score; 
}

int main()
{
  cin >> N;
  
  while(N != 0){

    for(int i = 0; i<201; i++){
      for(int k = 0; k<201; k++){
        state[i][k] = -1; 
      }
    }

    for(int i = 0; i<N; i++){
      cin >> arr[i]; 
    }

    cout << recr(0, N) << endl;

    cin >> N;
  }
}
