#include <map>
#include <iostream>
using namespace std;

typedef long long int ll;

const int BIT_SIZE = 100005; 
ll bit[BIT_SIZE]; 
ll bit2[BIT_SIZE]; 

ll sum(int n)
{
  ll sum = 0;
  while(n > 0){
    sum += bit[n];
    //clear right bit
    n -= (n & -n); 
  }
  return sum;
}

ll sum(int a, int b){
  return sum(b) - sum(a); 
}

void update(int k, int v)
{
  for(; k<BIT_SIZE; k+= (k & -k)){ 
    bit[k] += v; 
  } 
}

void update2(int k, int v){
  for(; k<BIT_SIZE; k+= (k & -k)){ 
    bit2[k] += v; 
  } 
}

ll sum2(ll n){
  ll sum = 0;
  while(n > 0){
    sum += bit2[n];
    //clear right bit
    n -= (n & -n); 
  }
  return sum;
}


int main()
{
  fill(bit,bit + BIT_SIZE,0); 
  fill(bit2,bit2 + BIT_SIZE,0); 
  int N,M;
  scanf("%d %d",&N, &M); 

  ll vals[N + 1]; 
  map<int,int> mp;
  for(int i = 1; i<=N; i++){
    int k; 
    scanf("%d", &k); 
    //if(mp.find(k) == mp.end()){
      //mp[k] = 0; 
    //}
    //mp[k]++; 
    vals[i] = k;
    update(i,k);
    update2(k,1);
  }

  while(M--){
    char c; 
    scanf(" %c", &c); 
    if(c == 'C'){
      int a,b;
      scanf(" %d %d", &a, &b); update(a,b - vals[a]); 
      update2(vals[a], -1); 
      update2(b,1);
      vals[a] = b; 
    }
    else if(c == 'S'){
      int a,b;
      scanf(" %d %d", &a, &b); 

      printf("%lld\n", sum(a - 1,b));
    }
    else{
      int a;
      scanf(" %d", &a); 
      printf("%lld\n", sum2(a));
    }
  }
}

