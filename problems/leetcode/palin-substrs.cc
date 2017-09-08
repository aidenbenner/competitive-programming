class Solution {
public:
    int isSubstr(vector<vector<int>>& DP, string& s, int st, int e){
      if(st == e) return true;
      if(st > e) return isSubstr(DP, s,e,st); 
      if(DP[st][e] != -1) return DP[st][e]; 
    

      if(s[st] != s[e]) return DP[st][e] = false;
      if(e - st <= 1) return true;
      return DP[st][e] = isSubstr(DP,s, st + 1, e - 1); 
    }
    int countSubstrings(string s) {
      vector<vector<int>> DP;
      for(int i = 0; i<s.size(); i++){
        DP.push_back(vector<int>());
        for(int k = 0; k<s.size(); k++){
          DP[i].push_back(-1);
        }
      }

      int count = 0; 
      for(int i = 0; i<s.size(); i++){
        for(int k = i; k<s.size(); k++){
          count += isSubstr(DP,s,i,k); 
        }
      }

      return count;
    }

};
