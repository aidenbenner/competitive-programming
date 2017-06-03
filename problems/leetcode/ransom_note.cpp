#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map < char,int > memo; 

      for(int i = 0; i<magazine.length(); i++){
        auto itr = memo.find(magazine[i]);
        if(itr == memo.end()){
          memo.insert(make_pair(magazine[i], 1)); 
        }
        else{
          itr->second++; 
        }
      }
      
      for(int i = 0; i<ransomNote.length(); i++){
        auto itr = memo.find(ransomNote[i]);
        if(itr == memo.end()) return false; 
        if(itr->second == 0) return false;
        itr->second--; 
      }
      return true;
    }
};
