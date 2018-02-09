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

bool gamesPlayed[4][4];
int T;

int getGamesPlayed(vector<int> points) {
    int sum = 0; 
      for(int i = 0; i<4; i++){
          for(int k = 0; k<4; k++){
              if(!gamesPlayed[i][k]){
                  gamesPlayed[i][k] = true;
                  gamesPlayed[k][i] = true;

                  points[i] += 3; 

                  sum += getGamesPlayed(points);

                  points[i] -= 2; 
                  points[k] += 1; 

                  sum += getGamesPlayed(points);

                  points[i] -= 1; 
                  points[k] += 2; 

                  sum += getGamesPlayed(points);
                  gamesPlayed[i][k] = false;
                  gamesPlayed[k][i] = false;
                  return sum;
              }
          }
      }
      for(int i = 0; i<points.size(); i++){
          if(i == T) continue;
          if(points[i] >= points[T]) return 0;
      }
      return 1;
}

int N; 
int main()
{
  std::ios_base::sync_with_stdio(false); 
  cin >> T;
  T--;
  int N;
  cin >> N;

  for(int i = 0; i<4; i++){
      for(int k = 0; k<4; k++){
          gamesPlayed[i][k] = i == k;
      }
  }

  vector<int> points; 
  points.resize(4); 

  while(N--){
      int a,b,as,bs;
      cin >> a >> b >> as >> bs;
      a--;
      b--;
      if(as > bs) {
          points[a] += 3;
      }
      else if(bs > as) {
          points[b] += 3;
      }
      else {
          points[b] += 1;
          points[a] += 1;
      }
      gamesPlayed[a][b] = true;
      gamesPlayed[b][a] = true;
  }

  cout << getGamesPlayed(points) << endl;
}
