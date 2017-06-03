#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector <int> > DP; 
    int maxProfit(vector<int>& prices, int cur, int sold, int trans)
    {
      if(sold >= trans){
        return 0; 
      }
      if(cur >= prices.size()){
        return 0; 
      }
      if(DP[cur][sold] != -1){
        return DP[cur][sold]; 
      }

      int p = 0; 
      int min = cur; 
      int max_prof = 0; 
      int max_transp = maxProfit(prices,cur+2, sold + 1, trans); 
      for(int i = cur; i<prices.size(); i++){
        if(prices[i] < prices[min]){
          min = i; 
        }
        if(prices[i] > prices[min]){
          if(prices[i] - prices[min] > max_prof){
            if(p < max_transp + prices[i] - prices[min]){
              max_prof = prices[i] - prices[min]; 
              int trans_p = maxProfit(prices,i+1, sold + 1, trans); 
              p = max(prices[i] - prices[min] + trans_p, p); 
            }
          }
        }
     }

      return DP[cur][sold] = p; 
    }

    int maxProfit(int k, vector<int>& prices) {
      if(prices.size() == 0){
        return 0; 
      }
      DP.clear(); 
      
      if(k > prices.size() / 2){
        int profit = 0; 
        for(int i = 0; i<prices.size() - 1; i++){
          profit += max(prices[i+1] - prices[i], 0);
        }
        return profit; 
      }


      int K =  min(k, (int)prices.size() / 2 + 1);
      DP.resize(prices.size()); 
      for(int i = 0; i<prices.size(); i++){
        DP[i].resize(K); 
        for(int j = 0; j<K; j++){
          DP[i][j] = -1; 
        }
      }

      int profit = maxProfit(prices, 0, 0, K); 
      return profit; 
    }
};

