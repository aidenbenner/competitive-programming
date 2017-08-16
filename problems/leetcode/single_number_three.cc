#include <map>

using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      map<int, int> mp;

      for(int i = 0; i<nums.size(); i++){
        if(mp.find(nums[i]) == mp.end()){
          mp[nums[i]] = 0; 
        }
        mp[nums[i]]++; 
      }

      vector<int> out; 
      for(auto itr = mp.begin(); itr != mp.end(); itr++){
        if(itr->second == 1){
          out.push_back(itr->first);
          if(out.size() == 2) break;
        }
      }

      return out;
    }
};
