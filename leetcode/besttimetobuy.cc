#include <algorithm>
#include <vector>
#include <iostream>
#define INF 1e9

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int min = INF; 
      int profit = 0;
      for(int i = 0; i<prices.size(); i++){
        if(prices[i] > min){
          profit += prices[i] - min; 
          min = prices[i];
        }
        if(prices[i] < min){
          min = prices[i]; 
        }
      }

      return profit; 
    }
};
