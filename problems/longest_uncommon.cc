#include <algorithm>
using namespace std;
class Solution {
  public:
    bool isSubstr(string a, string b){
      for(int i = 0; i<b.size(); i++){
        if(b[i] != a[0]) continue;

        bool sub = true;
        int inc = 0; 
        for(int k = 0; k<a.size(); k++){
          if(k + i + inc >= b.size()) {
            sub = false;
            break;
          }
          while(a[k] != b[k + i + inc]){
            inc++; 
            if(k + i + inc >= b.size()) {
              sub = false; 
              break;
            }
          }
        }

        if(sub){
          return true;
        }
      }
      return false; 
    }

    int findLUSlength(vector<string>& strs) {
      // always longest string that doesn't have a twin

      sort(strs.begin(), strs.end());

      int curr = -1; 
      for(int i = 0; i<strs.size(); i++){
        bool hit = false; 
        if(i != strs.size() - 1){
          while(strs[i] == strs[i + 1] && i < strs.size() - 1 ){
            i++; 
            hit = true;
          }
        }
        if(hit) continue; 
        // not duped
        bool issub = false; 
        for(int k = 0; k < strs.size(); k++){
          if(i == k){
            continue;
          }
          if(isSubstr(strs[i], strs[k])){
            issub = true;
            break;
          }
        }
        if(!issub){
          curr = max(curr, (int)strs[i].length()); 
        }
      }
      return curr;
    }
};


