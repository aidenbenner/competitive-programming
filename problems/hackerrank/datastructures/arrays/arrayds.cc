
#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>

#define INF 1e9
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 
int main()
{
  std::ios_base::sync_with_stdio(false); 
  scanf("%d", &N); 
  int arr[N]; 
  for(int i = 0; i<N; i++){
    scanf("%d", &arr[i]); 
  }

  for(int i = 0; i<N; i++){
    printf("%d ", arr[N - 1 - i]); 
  }
  
}
