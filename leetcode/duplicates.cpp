#include <unordered_set> 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> set; 
      for(int i = 0; i<nums.size(); i++){
        auto itr = set.find(nums[i]); 
        if(itr != set.end()){
          return true;
        }
        set.insert(nums[i]);
      }
      return false;
    }
};
