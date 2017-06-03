class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> out; 
      for(int i = 0; i<=num; i++){
        int count = 0; 
        for(int k = 0; k<32; k++){
          if(1 & (i >> k)){
            count++; 
          }
        }
        out.push_back(count); 
      }
      return out;
    }
};
