
#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end());

      if(citations.size() == 0){
        return 0; 
      }

      int mid = citations.size() / 2; 

      int hind = 0; 
      for(int i = citations.size() - 1; i>=0; i--){
        if(citations[i] > hind){
          hind++; 
        }
      }
      return hind;
    }
};
