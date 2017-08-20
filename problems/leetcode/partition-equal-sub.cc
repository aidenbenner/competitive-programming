class Solution {
public:
    bool canPartition(vector<int>& nums) {

      int total = 0; 
      for(int i = 0; i<nums.size(); i++){
        total += nums[i]; 
      }

      vector<vector<int>> DP(nums.size());
      for(int i = 0; i<nums.size() + 1; i++){
        DP.push_back(vector<int>());
        for(int k = 0; k<total / 2 + 2; k++){
          DP[i].push_back(-1);
        }
      }

      if(total % 2) return false;

      return SubEqSum(nums, nums.size(), total / 2, DP); 
    }

    bool SubEqSum(vector<int>& nums, int n, int sum, vector<vector<int>>& DP){
      if(n == 0 && sum == 0) return true;
      if(n <= 0) return false;
      if(sum == 0){
        return true;
      }
      if(sum < 0){
        return false;
      }
      if(DP[n][sum] != -1){
        return DP[n][sum];
      }

      return DP[n][sum] = SubEqSum(nums, n - 1, sum - nums[n - 1], DP) || SubEqSum(nums, n - 1, sum, DP); 
    }
};
