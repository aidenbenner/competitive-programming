
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      //build max table
      if(prices.size() == 0){
        return 0; 
      }
      
      int max_[prices.size()]; 

      max_[prices.size() - 1] = prices[prices.size() - 1]; 
      for(int k = prices.size() - 2; k >= 0; k--){
        max_[k] = max(prices[k], max_[k + 1]); 
      }
  
      int max_diff = 0; 
      for(int i = 0; i<prices.size() - 1; i++){
        int diff = max_[i + 1] - prices[i]; 
        if(diff > max_diff){
          max_diff = diff; 
        }
      }

      return max_diff; 
    }
};
