#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

const int BIT_SIZE = 1000005;


ll bit[BIT_SIZE]; 

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

ll find(ll freq){
  long lo = 1; 
  long high = BIT_SIZE;
  while(lo <= high){
    long mid = lo + (high-lo)/2;  
    if(freq >= sum(mid)){
      lo = mid + 1;
    }
    else{
      high = mid - 1; 
    }
  }
  return high;
}

void update(int k, int v)
{
  for(; k<BIT_SIZE; k+= (k & -k)) bit[k] += v; 
}

int main()
{
  fill(bit,bit + BIT_SIZE,0); 
  ll N;
  scanf("%lld", &N); 


  char ops[]; 
  int a[];
  int b[]; 

  for(int i = 0; i<N; i++){

  }



  unordered_map<ll,ll> mp;
  unordered_map<ll,ll> mpr;
  ll total = 0; 
  while(N--){
    char c; 
    scanf(" %c", &c); 
    if(c == 'N'){
      total++; 
      ll a,b;
      scanf(" %lld %lld", &a, &b); 
      update(b,1); 
      mp[a] = b;
      mpr[b] = a; 
    }
    else if(c == 'M'){
      ll a,b;
      scanf(" %lld %lld", &a, &b); 
      update(mp[a],-1);
      mp[a] = b;
      mpr[b] = a; 
      update(mp[a],1);
    }
    else{
      ll a;
      scanf(" %lld", &a); 
      ll out = mpr[find(total - a) + 1];
      printf("%lld\n", out); 
    }
  }

}
