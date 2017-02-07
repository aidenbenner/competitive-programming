#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long DP[2001][2001][2]; 

long long games(int home, int away, bool stress, int fin_score){
  if(home < 0){
    return 0;
  }
  if(away < 0){
    return 0;
  }
  if(DP[home][away][stress] != -1){
    return DP[home][away][stress]; 
  }
  if(stress){
    if(home == 0 && away == 0){
      return 1; 
    }
    if(home <= away){
      return 0; 
    }
    long long out = games(home - 1, away, stress, fin_score); 
    out +=  games(home, away - 1, stress, fin_score); 
    out %= MOD;
    return DP[home][away][stress] = out;
  }
  else{
    if(home == 0 && away == 0){
      return 1;
    }
    if(home > away && away != fin_score){
      return 0; 
    }
    long long out = games(home - 1, away, stress, fin_score); 
    out +=  games(home, away - 1, stress, fin_score); 
    out %= MOD;
    return DP[home][away][stress] = out;
  }
}

int main()
{
  int T; 
  cin >> T;

  for(int i = 1; i<=T;i++){
    
    string parse;
    cin >> parse; 
    int home, away; 
    sscanf(parse.c_str(), "%d-%d", &home, &away); 
    for(int i = 0; i<=home; i++){
      for(int k = 0; k<=away; k++){
        DP[i][k][0] = -1; 
        DP[i][k][1] = -1; 
      }
    }
    long long stress =  games(home,away, 1, away); 
    long long stressn = games(home,away, 0, away); 

    printf("Case #%d: %lld %lld\n", i, stress, stressn);
  }
}
