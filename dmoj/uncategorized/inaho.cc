#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include "inaho.h"

#define INF 1e9
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;


const int DIS_SET_SIZE = 100005;
int disp[DIS_SET_SIZE];
int disr[DIS_SET_SIZE];
int disp2[DIS_SET_SIZE];
int disr2[DIS_SET_SIZE];


int ds_create(int x){
  disp[x] = x; 
  disr[x] = 0; 
}

int ds_find(int x) {
  if(x != disp[x]) return ds_find(disp[x]); 
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
}

void Init(int N){
  ds_create(N);
}

void AddEdge(int U, int V){
  ds_merge(U,V);
}

void RemoveLastEdge();
int GetSize(int U);


