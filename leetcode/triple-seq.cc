
#define INF 1e9

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int max = -INF; 

      int count = 0; 
      for(int i = 0; i<nums.size(); i++){
        if(nums[i] > max){
          max = nums[i]; 
        }


      }
    }
};
