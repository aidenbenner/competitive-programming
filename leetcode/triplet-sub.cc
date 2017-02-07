#define INF 1e10
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      if(nums.size() < 3){
        return false;
      }
      long less = INF; 
      long second = INF;
      for(int i = 0; i<nums.size(); i++){
        if(nums[i] > second){
          return true;
        }
        if(less != INF && second > nums[i] && nums[i] > less){
          second = nums[i]; 
        }
        if(nums[i] < less){
          less = nums[i];
        }
      }
      return false;
    }
};
