class Solution {
public:

    int getSum(int n){
      return n * (n + 1) / 2;
    }

    int numberOfArithmeticSlices(vector<int>& A) {
      if(A.size() <= 2) return 0; 
      vector<int> diffs; 

      for(int i = 0; i<A.size() - 1; i++){
        diffs.push_back(A[i + 1] - A[i]); 
      }

      int total = 0; 
      int run = 0; 
      for(int i = 0; i<diffs.size() - 1; i++){
        if(diffs[i] == diffs[i + 1]) {
          run++; 
        }
        else{
          total += getSum(run);
          run = 0; 
        }
      }
      total += getSum(run); 
      return total; 
    }

};
