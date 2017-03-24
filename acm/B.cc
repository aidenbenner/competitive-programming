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

int N , K;  
int main()
{
  cin >> N;
  cin >> K; 
  string A;
  cin >> A; 

  if(N == K){
    cout << A << endl;
    return 0;
  }

  if(K > N){
    cout << "WRONGANSWER" << endl;
    return 0;
  }



  int let[26]; 
  for(int i = 0; i<N; i++){
    let[A[i] - 'a']++; 
  }

  char safe = ' '; 
  for(int i = 0; i<26; i++){
    if(let[i] == 0){
      safe = i + 'a';
    }
  }

  if(safe == ' '){
    cout << "WRONGANSWER" << endl;
    return 0;
  }

  for(int i = 0; i<N; i++){
    if(i < K){
      cout << A[i]; 
    }
    else{
      cout << safe; 
    }
  }

  cout << endl;
}
