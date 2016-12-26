#include <iostream>
#include <vector>

using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
  vector<int> check; 
  check.resize(nums.size() + 1); 

  for(int i = 0; i<nums.size(); i++){
    check[nums[i]] = 1; 
  }

  vector<int> out; 
  for(int k = 1; k<check.size(); k++){
    if(check[k] == 0){
      out.push_back(k); 
    }
  }
  return out; 
}
