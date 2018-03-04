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

int main()
{
  int cases;
  cin >> cases;

  for(int t = 1; t<=cases; t++){
    ull n,k;
    cin >> n >> k;

    ull top,bot; 

    top = n / 2;
    bot = n / 2 - 1;
    while(k != 0 && k != 1){
      if(n & 1){
        if(k & 1){ 
          //left 
          n = n > 1 - 1;
          top = n + 1;
          bot = n;
        }
        else {
          //right
          n = n > 1; 
          top = n;
          bot = n;
        }
      } else{
          n = n > 1;
          top = n;
          bot = n;
      }
      cout << n << endl;
      k = k > 1; 
    }
    printf("Case #%d: %llu %llu\n", t, bot, top);
  }
}






