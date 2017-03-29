#include <algorithm>
#include <map>
#include <multiset>
#include <utility>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end()); 
      
      set<int> st; 

      for(int i = 0; i<nums.size(); i++){
        st.insert(nums[i]); 
      }

      set<vector<int> > chck;

      vector<vector<int>> out; 
      for(int i = 0; i<nums.size(); i++){
        for(int k = i + 1; k<nums.size(); k++){
          if(i == k) continue;
          int sum = nums[i] + nums[k]; 
          int itr = st.count(0 - sum); 
          if(itr != 0){
            if(itr >= 2){
              vector<int> curr; 
              curr.push_back(nums[i]); 
              curr.push_back(nums[k]); 
              curr.push_back(0 - sum); 
              sort(curr.begin(), curr.end()); 
              auto itr = chck.find(curr);
              if(itr == chck.end()){
                chck.insert(curr); 
                out.push_back(curr); 
              }
            }
            else{
              vector<int> curr; 
              if(0 - sum != nums[i] && 0 - sum != nums[k]){
                curr.push_back(nums[i]); 
                curr.push_back(nums[k]); 
                curr.push_back(0 - sum); 
                sort(curr.begin(), curr.end()); 
                auto itr = chck.find(curr);
                if(itr == chck.end()){
                  chck.insert(curr); 
                  out.push_back(curr); 
                }
                out.push_back(curr); 
              }
            }
          }
        }
      }
    

      return out;
    }
};
