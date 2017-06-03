#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
  public:
    int minMoves(vector<int>& nums) {
      //move is incrementing n-1 elements by 1 
      int num_moves = 0; 

      sort(nums.begin(), nums.end()); 
      //takes at least max - min moves 

      for(int i = nums.size() - 1; i > 0; i--){
        int diff = nums[i] - nums[i - 1];
        num_moves += diff * (nums.size() - i); 
      }

      return num_moves; 
    }
};
