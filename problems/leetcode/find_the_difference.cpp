
#include <unordered_map>
#include <string>

using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
      unordered_map<char,int> check;
      for(int i = 0; i<s.length(); i++){
        auto itr = check.find(s[i]); 
        if(itr != check.end()){
          itr->second++; 
        }
        else{
          check.insert(make_pair(s[i],1));
        }
      }

      for(int k = 0; k<t.length(); k++){
        auto itr = check.find(t[k]); 
        if(itr == check.end()){
          return t[k];
        }
        itr->second--; 
      }
  

      auto test = check.begin(); 
      while(test != check.end()){
        if(test->second != 0){
          return test->first;
        }
        test++;
      }
      return 'a'; 
    }
};
