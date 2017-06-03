#include <unordered_set> 
#include <cstring> 
class Solution {
public:
    int firstUniqChar(string s) {
      int memo[255]; 

      for(int i = 0; i<255; i++){
        memo[i] = 0; 
      }
      for(int i = 0; i<s.size(); i++){
        memo[s[i]]++; 
      }

      for(int i = 0; i<s.size(); i++){
        if(memo[s[i]] == 1){
          return i; 
        }
      }
      return -1;
    }
};
