#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <map>
#include <unordered_map>

#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

const int DIS_SET_SIZE = 1000005;
int disp[DIS_SET_SIZE];
int disr[DIS_SET_SIZE];

int ds_create(int x){
  disp[x] = x; 
  disr[x] = 0; 
  return x;
}

int ds_find(int x) {
  if(x != disp[x]) return disp[x] = ds_find(disp[x]); 
  return x; 
}

int ds_merge(int x, int y){
  x = ds_find(x);
  y = ds_find(y); 

  if(disr[x] > disr[y]){
    disp[y] = x; 
  }
  else{
    disp[x] = y; 
  }
  if(disr[x] == disr[y])
    disr[y] = disr[y] + 1;
  return ds_find(x); 
}

int MEMO[1005][1005];
vector<int> arr; 

int N, K, M; 

int solve(int s, int mov){
  if(s >= M) return 0;
  if(s < 0) return 0; 
  if(mov <= 0) return 0; 
  if(s == M - 1) return 1;
  if(mov >= 1005) return solve(s,1004); 
  if(MEMO[s][mov] != -1) return MEMO[s][mov]; 

  int out = 0; 

  for(int i = s; i< M - s; i++){
    if(i == s){ out = max(out,1); continue; }
    if(ds_find(arr[s]) == ds_find(arr[i])){
      if(arr[i] == arr[s])
        out = 1 + max(out, solve(M - i, mov));
      else
        out = 1 + max(out, solve(M - i, mov - 1));
    }
      out = max(out, solve(s + 1, mov));
  }

  return MEMO[s][mov] = out;
}

int main()
{
  scanf("%d %d %d", &N, &K, &M); 

  int ma[K]; 
  int mb[K]; 
  for(int i = 0; i<K; i++){
    scanf("%d %d", &ma[i], &mb[i]); 
    ds_create(ma[i]); 
    ds_create(mb[i]); 
  }

  for(int i = 0; i<M; i++){
    for(int k = 0; k<M; k++){
        MEMO[i][k] = -1; 
    }
    int x;
    scanf("%d", &x); 
    ds_create(x); 
    arr.push_back(x); 
  }

  for(int i = 0; i<K; i++){
    ds_merge(ma[i], mb[i]); 
  }

  /** for(int i = 0; i < M; i++){
    if(mp.find(arr[i]) == mp.end()){
      mp[arr[i]] = count; 
      arr[i] = count;
      ds_create(count); 
      count++; 
    } else{
      arr[i] = mp[arr[i]];
    }
  }

  for(int i = 0; i<K; i++){
    if(mp.find(ma[i]) == mp.end()){
      mp[ma[i]] = count; 
      ma[i] = count;
      ds_create(count); 
      count++; 
    } else{
      ma[i] = mp[ma[i]];
    }
    if(mp.find(mb[i]) == mp.end()){
      mp[mb[i]] = count; 
      mb[i] = count;
      ds_create(count); 
      count++; 
    } else{
      mb[i] = mp[mb[i]];
    }
    ds_merge(ma[i],mb[i]);
  } **/

  printf("%d", solve(0, K)); 
}
