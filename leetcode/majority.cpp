#include <unordered_map> 
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      //find element that appears n/2 times

      int thresh = nums.size() / 2.0; 
      if(nums.size() % 2 == 1){
        thresh += 1; 
      }
      unordered_map<int,int> map; 
      for(int i = 0; i<nums.size(); i++){
        auto itr = map.find(nums[i]); 
        if(itr == map.end()){
          map.insert(make_pair(nums[i],1));
          itr = map.find(nums[i]); 
        }
        if(itr->second >= thresh){
          return nums[i]; 
        }
      }
      return -1; 
    }
};
