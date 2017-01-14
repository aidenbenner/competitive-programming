#include <unordered_set> 
using namespace std;
class Solution {
  public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()){
        return false; 
      }
      if(s.size() == 0) return true;
      int memo[255]; 
      for(int i = 0; i<255; i++){
        memo[i] = 0;
      }
      for(int i = 0; i<s.size(); i++){
        memo[s[i]]++;
        memo[t[i]]--;
      }
      for(int i = 0; i<255; i++){
        if(memo[i] != 0)
          return false;
      }


      return true;
    }
};
