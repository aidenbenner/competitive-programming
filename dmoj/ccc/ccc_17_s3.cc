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

  int arr[N]; 
  int combs[N]; 
  for(int i = 0; i<N; i++){
    combs[i] = 0;
    cin >> arr[i]; 
  }

  sort(arr,arr+N); 

  int l = 0; 
  int r = N - 1; 
  
  int count = 1; 
  int out = 1; 
  int max_sum = 0; 
  while(l < r){
    int sum = arr[l] + arr[r]; 
    int next_sum = arr[l + 1] + arr[r-1]; 

    if(next_sum == sum){
      count++; 
      combs[count]++;
      l++;
      r--; 
      out = max(count,out);
      continue;
    }
    cout << "hit" << endl;
    count = 0; 
    combs[0]++; 
    int diffA = arr[l+1] - arr[l]; 
    int diffB = arr[r] - arr[r-1]; 
    if(diffA > diffB){
      l++;
    }
    else{
      r--; 
    }
  }
  cout << out << "  " <<  combs[out - 1] << endl;

}
