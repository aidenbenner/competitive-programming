#include <cstdio>
#include <vector>
#define INF 1e9

int A,B,N;
int *mtl;
int def[] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int MEMO[7001];

int dist(int n){
  if(MEMO[n] != INF){
    return MEMO[n];
  }
  if(n <= 0){
    return 1; 
  }
  int counter = 0; 
  for(int i = 0; i<N; i++){
    if(n == mtl[i]){
      continue;
    }
    if(n - A >= mtl[i] && mtl[i] >= n - B){
      counter += dist(mtl[i]);
    }
  }
  for(int i = 0; i<14; i++){
    if(n == def[i]){
      continue;
    }
    if(n - A >= def[i] && def[i] >= n - B){
      counter += dist(def[i]);
    }
  }
  return MEMO[n] = counter;
}

int main(){
  scanf("%d %d %d", &A, &B, &N);
  mtl = new int[N+14];

  mtl[N] = 0;
  for(int i = 0; i<7001; i++){
    MEMO[i] = INF;
  }

  for(int i = 0; i<N; i++)
    scanf("%d", &mtl[i]);
  printf("%d", dist(7000));
}
