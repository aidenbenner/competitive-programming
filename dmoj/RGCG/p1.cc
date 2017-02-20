#include <bits/stdc++.h>

#define INF 1e9 
#define eps 1e-9 
using namespace std;

typedef vector<int> VI; 
int N, D;

int main(){
  cin >> N;
  cin >> D;

  if(N == 0){ cout << 0; return 0;} 

  int combo = 1; 

  int lastX; 
  int lastY; 
  cin >> lastX;
  cin >> lastY; 

  int currX;
  int currY;
  int maxCombo = 1; 
  for(int i = 0; i<N-1; i++){
    cin >> currX;
    cin >> currY;

    int deltaX = currX - lastX;
    int deltaY = currY - lastY;

    double dis = deltaY * deltaY + deltaX * deltaX;
    dis = sqrt(dis); 

    if(dis < D + eps){
      combo++; 
      if(combo > maxCombo){
        maxCombo = combo;
      }
    }
    else{
      combo = 0;
    }
    lastX = currX;
    lastY = currY;
  }
  cout << maxCombo;
}
