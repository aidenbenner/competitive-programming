#include <iostream>
#include <algorithm>
#include <vector>


class Solution {
public:

  int DP[][][]; 
  vector<int> &maxes;

 int profit(vectr<int>& prices, , int last, int bought, int k)
  {
    int p = 0; 
    if(bought >= k){
      return 0; 
    }
    if(bought == k - 1){
      p = 0; 
      for(int i = last + 1; i < prices.size(); i++){
        if(maxes[i] - prices[i] > p){
          p = maxes[i] - prices[i]; 
        } 
      }
      return p; 
    }

    for(int i = last + 1; i < prices.size(); i++){
      if(maxes[i] - prices[i] > p){
        p = max(p,maxes[i] - prices[i] + profit(prices,i,bought + 1,k));
      } 
    }
    //otherwise return the max of all other buys

  }
    int maxProfit(vector<int>& prices) {
      if(prices.size() == 0){
        return 0; 
      }

      int profit = 0; 
      int maxa[prices.size()]; 
      maxa[prices.size() - 2]; 

      int mina[prices.size()]; 
      mina[prices.size() - 2]; 

      for(int i = prices.size() - 2; i>=0; i--){
        maxa = max(maxa[i+1], prices[i]); 
      }

    }
};
