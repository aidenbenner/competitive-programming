#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

const int BIT_SIZE = 100005;


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


  char ops[N]; 
  ll a[N];
  fill(a, a + N, -1); 
  ll b[N]; 
  fill(b, b + N, -1); 
  int k[N]; 
  fill(k, k + N, -1); 

  vector<ll> all; 

  for(int i = 0; i<N; i++){
    scanf(" %c", &ops[i]); 
    char c = ops[i];
    if(c == 'N'){
      scanf(" %lld %lld", &a[i], &b[i]); 
      all.push_back(b[i]); 
    }
    else if(c == 'M'){
      scanf(" %lld %lld", &a[i], &b[i]); 
      all.push_back(b[i]); 
    }
    else{
      scanf(" %lld", &a[i]); 
    }
  }

  map<ll, int> small; 
  sort(all.begin(), all.end()); 
  ll last = -1; 
  int ind = 3; 
  for(int i = 0; i<all.size(); i++){
    if(all[i] == last) continue;
    last = all[i]; 
    small[all[i]] = ind; 
    ind++; 
  }

  unordered_map<ll,ll> mp;
  unordered_map<ll,ll> mpr;
  ll total = 0; 
  for(int i = 0; i<N; i++){
    char c; 
    c = ops[i]; 
    if(c == 'N'){ 
      total++; 
      ll A,B;
      A = a[i]; 
      B = small[b[i]];
      cout << B << endl;
      update(B,1); 
      mp[A] = B;
      mpr[B] = A; 
    }
    else if(c == 'M'){
      ll A,B;
      A = a[i]; 
      B = small[b[i]];
      cout << B << endl;
      update(mp[A],-1); 
      mp[A] = B;
      mpr[B] = A; 
      update(mp[A],1);
    }
    else{
      ll A;
      A = k[i]; 
      ll out = mpr[find(total - A) + 1];
      printf("%lld\n", out); 
    }
  }

}
