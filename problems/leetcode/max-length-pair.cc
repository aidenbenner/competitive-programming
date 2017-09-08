class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      if(pairs.size() == 0) return 0; 
      vector<int> DP; 
      for(int i = 0; i<pairs.size(); i++){
        DP.push_back(-1); 
      }

      int out = 1; 
      for(int i = 0; i<pairs.size(); i++){
        out = max(out, solve(DP, pairs, i)); 
      }
      return out;
    }

    int solve(vector<int>& DP, vector<vector<int>>& pairs, int pair){
      if(DP[pair] != -1) return DP[pair];

      int curr = 1; 

      int a = pairs[pair][0]; 
      int b = pairs[pair][1]; 

      for(int i = 0; i<pairs.size(); i++){
        if(i == pair) continue;
        int c = pairs[i][0]; 
        int d = pairs[i][1]; 
        if(b < c){
          curr = max(curr, 1 + solve(DP, pairs, i)); 
        }
      }

      return DP[pair] = curr;
    }
};
