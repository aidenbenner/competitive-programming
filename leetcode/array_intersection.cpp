
#include <unordered_map> 
using namespace std;
typedef unordered_map<int,int> Map; 
class Solution {
public:

  unordered_map<int, int> get_freq(vector<int>&nums){
    Map mp; 

    for(int i = 0; i<nums.size(); i++){
      auto itr = mp.find(nums[i]);
      if(itr == mp.end()){
        mp.insert(make_pair(nums[i],0)); 
        itr = mp.find(nums[i]);
      }
      itr->second++; 
    }
    return mp; 

  }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      auto mp1 = get_freq(nums1); 
      auto mp2 = get_freq(nums2); 

      vector<int> out; 
      auto strt = mp1.begin(); 
      while(strt != mp1.end()){
        auto other = mp2.find(strt->first); 
        if(other != mp2.end()){
          int minN = min(other->second, strt->second); 

          for(int i = 0; i<minN; i++){
            out.push_back(strt->first); 
          }
        }
        strt++; 
      }
      return out; 
    }
};
