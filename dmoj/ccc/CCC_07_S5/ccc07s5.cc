#include <cstdio>
#include <iostream>
#include <cmath>

#define INF 1e9
int N,K,W, T;

using namespace std;
int main()
{
  scanf("%d", &T);
  while(T--){ 

    scanf("%d %d %d", &N, &K, &W);
    int pins[N];
    for(int i = 0; i<N; i++){
      scanf("%d", &pins[i]);
    }

    int MEMO[K+1][N];
    int sum[N]; 
    for(int i = 0; i<N; i++){
      sum[i] = 0;
      for(int k = 0; k<W && k+i<N; k++){
        sum[i] += pins[k + i];
      }
    }

    //2D DP 
    for(int i = 0; i<=K; i++)
      for(int k = 0; k<N; k++)
        if(i == 0)
          MEMO[i][k] = 0;
        else
          MEMO[i][k] = -1; 

    //for each ball
    for(int i = 1; i<=K; i++){
      //for each pin 
      for(int j = N-1; j>=0; j--){
        if(j >= N-W)
          MEMO[i][j] = sum[j]; 
        else
          MEMO[i][j] = max(MEMO[i-1][j+W] + sum[j], MEMO[i][j+1]);
      }
    }
    printf("%d\n", MEMO[K][0]);
  }
}



