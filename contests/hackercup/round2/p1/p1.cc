#include <iostream>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <queue>
#include <unordered_set> 
#include <cstring>
#include <cmath>

#define INF 1e9 

using namespace std;

int main()
{
  int T; 
  cin >> T;  

  for(int test = 1; test <= T; test++){
    int N, M, K;
    cin >> N >> M >> K; 
    int output = 0; 
    
    if( (N-1) < K || (M - K - 3) < K ){
      output = -1; 
      cout << "Case #" << test << ": " << output << endl; 
      continue;
    }

    int a = (N/K); 
    int b = (M/K); 
    output = min(a ,b ); 
    cout << "Case #" << test << ": " << output << endl; 
  }
}
