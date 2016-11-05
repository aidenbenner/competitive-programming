#include <cstdio>
#define INF 1e9


int R,C,K;
int MEMO[26][26];
bool cat[26][26];
int dp(int x, int y){
  if(MEMO[y][x] != -INF){
    return MEMO[y][x];
  }
  if(x == 1 && y == 1){
    return 1;
  }
  int out = 0;
  if(y-1 >= 1){
    if(!cat[y-1][x]){
      out += dp(x,y-1);
    }
  }
  if(x-1 >= 1){
    if(!cat[y][x-1]){
      out += dp(x-1,y);
    }
  }
  return MEMO[y][x] = out;
}


int main(){
  scanf("%d %d %d", &R, &C, &K); 
  for(int i = 0; i<26; i++)
    for(int k = 0; k<26; k++)
      cat[i][k] = false, MEMO[i][k] = -INF;
  for(int i = 0; i<K; i++){
    int x, y;
    scanf("%d %d", &y, &x);
    cat[y][x] = true;
  }
  printf("%d", dp(C,R));
}
