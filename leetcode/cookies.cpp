
#include <vector> 
#include <algorithm> 

using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(), g.end()); 
      sort(s.begin(), s.end()); 

      int content = 0; 
      int cp = 0; 
      for(int i = 0; i<g.size(); i++){
        if(cp >= s.size()) break; 
        
        //check if child at i is sat with cookie at cp 
        if(g[i] <= s[cp]){
          content++;
        } 
        else{
          i--; 
        }
        cp++;
      }
      return content;
    }
};
