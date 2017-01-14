class Solution {
public:
    int climbStairs(int n) {

      int dp[n+1];
      for(int i = 0; i<n+1; i++){
        dp[i] = -1; 
      }
      return recur(n,dp); 
        
    }

    int recur(int n, int dp[]){
      if(n == 0){
        return 1; 
      }
      if(n < 0){
        return 0; 
      }

      if(dp[n] != -1){
        return dp[n]; 
      }

      return dp[n] = recur(n-1,dp) + recur(n-2,dp); 
    }

};

