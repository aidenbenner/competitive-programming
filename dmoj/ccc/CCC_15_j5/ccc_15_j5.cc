#include <cstdio>
#include <cstdlib>
#include <cstring>


int N, K; 

int MEMO[251][251][251]; 


int solve (int n, int k, int min){
  if(min * k > n){
    return 0; 
  }
  if(n == k * min) {
    return 1; 
  }
  if(n < k){
    return 0;
  }  

  if(k == 1) { 
    return 1;
  }


  if(MEMO[n][k][min] != -1){
    //printf("%d %d %d %d\n",n,k,min,MEMO[n][k][min]);
    return MEMO[n][k][min];
  }

  int out = 0;
  for(int i = min; i<=n; i++){
    out += solve(n-i,k-1,i);
  }
  //printf("%d %d %d %d\n",n,k,min,out);

  return MEMO[n][k][min] = out; 
}


int main () 
{
  memset(MEMO, -1, 251 * 251 * 251 * sizeof(int)); 
  scanf("%d %d", &N, &K); 
  printf("%d", solve(N,K,1));
}
