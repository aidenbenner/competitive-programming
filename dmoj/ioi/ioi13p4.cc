#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>

#define INF 1e9
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 

int tryCombination(int S[]); 
void answer(int S[], int D[]);

void exploreCave(int N){
  
  int map[N]; 
  fill(map, map + N, -1); 

  int comb[N]; 
  fill(comb, comb + N, 0); 

  for(int i = 0; i<N; i++){
    int k = tryCombination(comb); 
    if(k == -1) k = 5001; 
    bool open = i < k; 

    int lower = 0; 
    int upper = N - 1;  

    while(lower <= upper){
      int mid = lower + (upper - lower) / 2;

      if(lower == upper){
        map[lower] = i; 
        //need to make sure we set to open
        int c = tryCombination(comb); 
        if(c == -1) c= 5001; 
        bool isopen = i < c;
        if(!isopen){
          comb[lower] = comb[lower] == 1 ? 0 : 1; 
        }
        break;
      }

      for(int h = mid + 1; h<=upper; h++){
        if(map[h] != -1){
          continue;
        }
        comb[h] = comb[h] == 1 ? 0 : 1; 
      }

      int currComb = tryCombination(comb); 
      if(currComb == -1) currComb = 5001; 
      bool nextOpen = i < currComb;
      if(nextOpen != open){
        lower = mid + 1; 
      }
      else{
        upper = mid; 
      }
      open = nextOpen;
    }

  }

  answer(comb, map); 
}


