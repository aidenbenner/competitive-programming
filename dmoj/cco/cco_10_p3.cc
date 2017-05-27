#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

const int BIT_SIZE = 2e7 + 5;


ll bit[BIT_SIZE]; 

int sum(int n)
{
  int sum = 0;
  while(n > 0){
    sum += bit[n];
    n -= (n & -n); 
  }
  return sum;
}

int sum(int a, int b){
  return sum(b) - sum(a); 
}

int bst_find(int freq){
  int low = 1; 
  int high = BIT_SIZE - 1;

  while(low <= high){
    int mid = (high + low) >> 1; 
    if(sum(mid) < freq){
      low = mid + 1; 
    } else{
      high = mid - 1; 
    }
  }
  return low; 
}

ll find(ll freq){
  if(freq == 0){
    int out = 0; 
    return bst_find(0);
  }
  int idx = 0; 
  long  bitmask = 1 << 20;
  while(bitmask != 0 && idx < BIT_SIZE) { 
    long tmp = idx + bitmask;
    if(freq >= bit[tmp]) {
      idx = tmp;
      freq -= bit[tmp]; 
    }
    bitmask >>= 1; 
  }
  if(freq != 0)
    return -1; 
  else
    return idx;
}



void update(int k, int v)
{
  for(; k<BIT_SIZE; k+= (k & -k)) bit[k] += v; 
}

int mp[ 1000005];
int mpr[1000005];

int main()
{
  //fill(bit,bit + BIT_SIZE,0); 
  ll N;
  scanf("%lld", &N); 

  priority_queue<int> all;

  char ops[N]; 
  ll a[N];
  ll b[N]; 
  int k[N]; 


  for(int i = 0; i<N; i++){
    scanf(" %c", &ops[i]); 
    if(ops[i] == 'N' || ops[i] == 'M'){
      scanf("%lld %lld", &a[i], &b[i]); 
      all.push(b[i]); 
    }
    else{
      scanf("%d", &k[i]); 
    }
  }

  unordered_map<ll, int> small; 
  int ind = 3; 
  int tot = all.size(); 
  while(!all.empty()){
    small[all.top()] = ind;
    all.pop(); 
    ind++; 
  }

  ll total = 0; 
  for(int i = 0; i<N; ++i){
    char c; 
    c = ops[i]; 
    if(c == 'N'){ 
      total++; 
      mp[a[i]] = small[b[i]];
      mpr[small[b[i]]] = a[i]; 
      update(mp[a[i]],1);
    }
    else if(c == 'M'){
      update(mp[a[i]],-1); 
      mp[a[i]] = small[b[i]];
      mpr[small[b[i]]] = a[i]; 
      update(mp[a[i]],1);
    }
    else{
      printf("%lld\n", mpr[bst_find(k[i])]);
    }
  }
}
