#include <unordered_map>
#include <iostream>

using namespace std; 
class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

      vector<int> out; 
      unordered_map<int, bool> map; 

      for(int i = 0; i<nums1.size(); i++){
        map.insert(make_pair(nums1[i],false)); 
      }

      for(int i = 0; i<nums2.size(); i++){
        auto itr = map.find(nums2[i]); 
        if(itr == map.end()){
          continue;
        }
        if(itr->second){
          continue;
        }
        
        itr->second = true; 
        out.push_back(nums2[i]); 
      }
      return out; 
    }
};
