#include <iostream>
using namespace std;

const int BIT_SIZE = 100005; 
int bit[BIT_SIZE]; 

int sum(int n)
{
  int sum = 0;
  while(n > 0){
    sum += bit[n];
    //clear right bit
    n -= (n & -n); 
  }
  return sum;
}

int sum(int a, int b){
  return sum(b) - sum(a); 
}

void update(int k, int v)
{
  for(; k<BIT_SIZE; k+= (k & -k)) bit[k] += v; 
}

int main()
{
  fill(bit,bit + BIT_SIZE,0); 
  int N,M;
  scanf("%d %d",&N, &M); 

  for(int i = 1; i<=N; i++){
    int k; 
    scanf("%d", &k); 
    update(i,k);
  }

  while(M--){
    char c; 
    scanf("%c", &c); 
    if(c == 'C'){
      int a,b;
      scanf("%d %d", &a, &b); 
      update(a,b); 
    }
    if(c == 'S'){
      int a,b;
      scanf("%d %d", &a, &b); 
      printf("%d", sum(a - 1,b));
    }

  }


  int S,Q; 
}
