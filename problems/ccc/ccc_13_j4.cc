#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

int N; 
vector<int> a;
int main()
{
  scanf("%d", &N); 
  int s;
  scanf("%d", &s); 

  for(int i = 0; i<s; i++){
      int tmp;
      scanf("%d", &tmp); 
      a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  
  int ind = 0; 
  while(N >= 0){
      N -= a[ind];
      ind++;
  }
  ind--;

  printf("%d\n",ind);
}
