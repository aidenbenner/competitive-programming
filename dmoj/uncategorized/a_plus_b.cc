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

#define SIZE 1000000
int c[SIZE * 2 + 1];

int main()
{
  cin >> N;
  while(N--){

    string as; 
    string bs;
    cin >> as >> bs; 
    fill(c, c + SIZE * 2 + 1, 0);
    for(int i = 0; i<SIZE * 2 + 1; i++){

      if(c[i] > 10)
      {
        c[i] = c[i] % 10;
        c[i + 1] += 1;
      }

      if(i < as.size())
        c[i] += as[i] - '0' + bs[i] - '0'; 

      if(c[i] > 10)
      {
        c[i] = c[i] % 10;
        c[i + 1] += 1;
      }
    }
    int i = SIZE * 2;
    while(c[i] == 0){
      i--; 
    }
    for(; i>=0; i--){
      cout << c[i]; 
    }
    cout << endl;

  }
}
