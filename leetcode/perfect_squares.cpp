#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;
class Solution {

public:
    int recur(int n,vector<int> &squares,int dp[]){
      if(n == 0){
        return 0; 
      }
      if(n < 0){
        return INF; 
      }
      if(dp[n] != -1){
        return dp[n]; 
      }

      int minA = INF; 
      for(int i = 0; i<squares.size(); i++){
        if(squares[i] > n){
          break;
        }
        int curr = recur(n - squares[i],squares,dp); 
        if(curr == 0){
          minA = 0;
          break;
        }
        if(curr < minA){
          minA = curr;
        }
      }
      return dp[n] = 1 + minA; 
    }

    int numSquares(int n) {
      //generate squares list
      vector<int> squares; 

      int dp[n + 1]; 
      for(int i = 0; i<n + 1; i++){
        dp[i] = -1;
      }

      for(int i = 1; i * i <= n; i++){
        squares.push_back(i * i); 
      }
      return recur(n,squares,dp); 
    }

};
