#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>

#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define MOD 1e9 + 7

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 
int DP[31][31][31][31]; 

//1 for p1 or 2 for p2
int canwin(int a, int b, int c, int d){
  if(a < 0 || b < 0 || c < 0 || d < 0) return 0;
  if(DP[a][b][c][d] != -1) return DP[a][b][c][d]; 

  int mv1 = canwin(a - 2, b - 1, c, d - 2); 
  int mv2 = canwin(a - 1, b - 1, c - 1, d - 1); 
  int mv3 = canwin(a , b , c - 2, d - 1); 
  int mv4 = canwin(a , b - 3, c , d); 
  int mv5 = canwin(a - 1, b , c , d - 1); 

  if(mv1 == mv2 && mv2 == mv3 && mv3 == mv4 && mv4 == mv5 && mv5 == 0){
    return DP[a][b][c][d]=1;  //current player loses always so player before won 
  }
  return DP[a][b][c][d]=0; 
}


int main()
{
  for(int a = 0; a<31; a++)
    for(int b = 0; b<31; b++)
      for(int c = 0; c<31; c++)
        for(int d = 0; d<31; d++)
          DP[a][b][c][d] = -1; 
    
  scanf("%d", &N); 
  for(int T = 1; T<=N; T++){
    int a[4]; 
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]); 
    bool out = canwin(a[0],a[1],a[2],a[3]); 
    if(out){
      printf("Roland\n"); 
      continue;
    }
    printf("Patrick\n"); 
  }
}
