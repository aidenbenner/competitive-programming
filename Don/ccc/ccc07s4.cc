#include <cstdio>
#include <vector>
#define INF 1e9
using namespace std;
typedef vector<int> vi ;
int MEMO[10000];
vector<vi> ind; 
int N; 

int dp(int n){
  if(MEMO[n] != INF){
    return MEMO[n];
  }
  if(n == 1){
    return 1;
  }
  int count = 0;
  for(int i = 0; i<ind[n].size(); i++){
    count += dp(ind[n][i]);
  }
  return MEMO[n] = count;
}


int main(){
  ind.resize(100000);
  scanf("%d" , &N);
  for(int i = 0; i<10000; i++){
    MEMO[i] = INF; 
  }

  while(true){
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == 0 && y == 0) break;
    ind[y].push_back(x);
  }
  printf("%d", dp(N));
}
