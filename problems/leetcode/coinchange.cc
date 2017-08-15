#include <algorithm>
using namespace std;
class Solution {
public:

    int solve(int *DP, vector<int>&coins, int amount){
      if(amount < 0){
        return -1; 
      }
      if(DP[amount] != -2){
        return DP[amount];
      }
      if(amount == 0){
        return 0; 
      }

      int curr = -1;  
      for(int i = 0; i<coins.size(); i++){
        int next = solve(DP, coins, amount - coins[i]);
        if(next == -1) continue;
        next = next + 1;
        if(curr == -1){
          curr = next;
        }
        else{
          curr = min(curr,next);
        }
      }
      return DP[amount] = curr; 
    }

    int coinChange(vector<int>& coins, int amount) {
      int DP[amount + 1];
      for(int i = 0; i<amount + 1; i++){
        DP[i] = -2; 
      }
      return solve(DP, coins, amount);
    }

};
