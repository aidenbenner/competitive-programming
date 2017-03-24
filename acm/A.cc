#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define INF 1e9
#define EPS 1e-13
#define pb push_back
#define MOD 1000000007

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 
int main()
{
  cin >> N;

  int outfits = 0;

  for(int i = 0; i<N; i++){
    for(int k = i; k<N; k++){
      if(i != k) outfits++; 
    }
  }

  cout << 2*outfits <<endl;
}
