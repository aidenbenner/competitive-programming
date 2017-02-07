#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int recr(int n, vector<int>& nums, int * DP)
    {
      if(DP[n] != -1) 
      {
        return DP[n]; 
      }
      if(n == 1){
        return DP[n] = 1;
      }
      if(n == 0)
        return DP[n] = 0; 

      int ret = 1; 
      for(int i = 0; i<n-1; i++){
        if(nums[n - 1] > nums[i]){
          ret = max(recr(i + 1, nums, DP) + 1, ret); 
          continue; 
        }
      }
      return DP[n] = ret; 
    }

    int lengthOfLIS(vector<int>& nums) {
      int DP[nums.size() + 1]; 
      fill(DP, DP + nums.size() + 1, -1); 
      recr(nums.size(),nums, DP);

    
      int ret = 0; 
      for(int i = 0; i<nums.size() + 1; i++){
        recr(nums.size() - i, nums, DP); 
        if(ret < DP[i]){
          ret = DP[i];
        }
      }
      return ret;
    }
};

int main(){
  Solution s;
  vector<int> input; 
  input.push_back(1);
  input.push_back(3);
  input.push_back(6);
  input.push_back(7);
  input.push_back(9);
  input.push_back(4);
  input.push_back(10);
  input.push_back(5);
  input.push_back(6);
  cout << s.lengthOfLIS(input) <<  endl; 
}
