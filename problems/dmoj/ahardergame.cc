#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

int N; 
int main()
{
  std::ios_base::sync_with_stdio(false); 
  scanf("%d", &N); 
  int a[N]; 
  for(int i = 0; i<N; i++){
    scanf("%d", &a[i]);
  }

  // make the move that gives you the lead
  int i = 0; 
  int j = N - 1;

  int coins = 0; 
  while( i < j ){

    int costLeft = a[i]- max(a[i + 1], a[j]); 
    int costRight = a[j]- max(a[j - 1], a[i]); 
    if(costLeft > costRight){
      coins += a[i];
      if(a[i+1] > a[j]){
        i++; 
      }
      else{
        j--;
      }
      i++; 
    }
    else{
      coins += a[j];
      if(a[i] > a[j - 1]){
        i++;
      }
      else{
        j--;
      }
      j--; 
    }
  }
  if(i <= j){
    coins += max(a[i], a[j]); 
  }

  printf("%d", coins); 
}
