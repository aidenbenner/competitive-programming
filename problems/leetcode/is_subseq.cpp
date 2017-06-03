class Solution {
public:
    bool isSubsequence(string s, string t) {
      if(s == ""){
        return true;
      }
      int inc = 0; 
      for(int i = 0; i<t.length(); i++){
        if(t[i] == s[inc]){
          inc++; 
        }
        if(inc == s.size()){
          return true;
        }
      }
      return false; 

        
    }
};
