A
#include <vector>
using namespace std;
class Solution {
  public:

    
    int rob_rec(int n, vector<int>& nums, int able, int first, vector<vector<vector<int> > >   & DP){
      if(n == nums.size() - 1){
        if(first){
          return 0; 
        }
        else{
          if(able){
            return nums[n];  
          }
          return 0; 
        }
      }
      else if(n >= nums.size()){
        return 0; 
      }

      if(DP[n][able][first] != -1){
        return DP[n][able][first];
      }

      if(n == 0){
        int out = nums[0] + rob_rec(n+1,nums,false,true, DP); 
        out = max(out, rob_rec(n+1,nums,true,false, DP));
        return DP[n][able][first] = out;
      }

      if(!able){
        return DP[n][able][first] = rob_rec(n+1,nums, true, first, DP);
      }

      int out = rob_rec(n + 1, nums, true, first, DP);
      out = max(out, nums[n] + rob_rec(n+1,nums,false, first, DP));
      return DP[n][able][first] = out;
    }

    int rob(vector<int>& nums) {
      if(nums.size() == 1){
        return nums[0]; 
      }
      vector<vector<vector<int> > > DP;
      DP.resize(nums.size()); 
      for(int i = 0; i<nums.size(); i++){
        DP[i].resize(2);
        for(int k = 0; k<2; k++){
          DP[i][k].resize(2);
          for(int j = 0; j<2; j++){
            DP[i][k][j] = -1;
          }
        }
      }
      return rob_rec(0,nums,1,1, DP); 
    }
};
