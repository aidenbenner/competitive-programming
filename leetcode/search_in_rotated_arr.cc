using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
      //do bst to find pivot index
      if(nums.size() == 0){
        return -1; 
      }

      int top = nums.size()- 1; 
      int bot = 0; 

      int lowest = 0; 
      while(bot < top){
        int mid = bot + (top - bot) / 2; 
        if(nums[mid] < nums[bot]){
          top = mid; 
          bot += 1; 
        }
        else if(nums[mid] > nums[top]){
          bot = mid + 1; 
        }
        else{
          lowest = bot; 
          break; 
        }
        lowest = mid; 
      }

      top = lowest + nums.size() - 1; 
      bot = lowest; 

      int mid = bot;
      int val = 0; 
      while(bot < top){
        mid = bot + (top - bot) / 2; 
        if(target == nums[mid % nums.size()]){
          return mid % nums.size(); 
        }
        else if (target > nums[mid % nums.size()]){
          bot = mid + 1;  
        }
        else{
          top = mid - 1;
        }
      }

      if(nums[bot % nums.size()] == target){
        return bot % nums.size(); 
      }
      return -1; 

}};
