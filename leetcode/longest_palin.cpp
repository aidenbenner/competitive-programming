#include <unordered_map> 
class Solution {
public:

    int longestPalindrome(string s) {
      //count number of even characters...
      //find max odd character 
      //return sum 

      int chars[256]; 
      for(int i = 0; i<256; i++){
        chars[i] = 0; 
      }

      for(int i = 0; i<s.length(); i++){
        chars[s[i]]++; 
      }
      
      int even_sum = 0;
      int odd_max = 0; 
      int odd_index = 0; 
      bool first = true; 

      for(int i = 0; i<256; i++){
        if(chars[i] % 2 == 1){
          if(chars[i] > odd_max){
            odd_max = chars[i]; 
            
            if(!first){
              even_sum += chars[odd_index] - 1; 
            }

            first = false; 
            odd_index = i; 
          }
          else{
            even_sum += chars[i] - 1; 
          }
          continue; 
        }
        if(chars[i] == 0){
          continue; 
        }
        even_sum += chars[i]; 
      }


      return even_sum + odd_max; 
    }
};


