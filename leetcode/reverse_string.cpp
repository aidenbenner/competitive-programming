class Solution {
public:
    string reverseString(string s) {
      string out; 
      for(int i = 0; i<s.length(); i++){
        out += s[s.length() - 1 - i]; 
      }
      return out; 
    }
};
