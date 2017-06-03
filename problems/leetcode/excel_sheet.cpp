class Solution {
public:
    int titleToNumber(string s) {
      int sum = 0; 
      int incre = 1; 
      bool first = true; 
      for(int i = s.length() - 1; i>=0; i--){
        sum += (s[i] - 'A' + 1) * incre; 
        incre *= 26;
      }

      return sum;
    }
};
