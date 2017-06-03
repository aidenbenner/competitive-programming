class Solution {
  public:
    void moveZeroes(vector<int>& nums) {

      for(int i = 0; i<nums.size(); i++){
        if(nums[i] == 0){
          //swap with next non-zero
          for(int k = i+1; k<nums.size(); k++){
            if(nums[k] != 0){
              int temp = nums[i];
              nums[i] = nums[k];
              nums[k] = temp; 
              break; 
            }
          }
        }

      }
    }
};
