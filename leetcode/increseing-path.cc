#include <vector>
#include <algorithm>
#include <iostream>
#define INF (int)1e9

using namespace std;

class Solution {
public:
    int recr(int last, int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& DP) {
      if(x >= matrix.size() || (x < 0)){
          return 0; 
      }
      if(y >= matrix[0].size() || (y < 0)){
          return 0; 
      }
      int ret = 0; 
      int curr = matrix[x][y]; 
      if(last < curr){
        if(DP[x][y] != -1){
          return DP[x][y]; 
        }
        ret = max(ret, recr(curr, x+1, y, matrix, DP));
        ret = max(ret, recr(curr, x-1, y, matrix, DP));
        ret = max(ret, recr(curr, x, y+1,  matrix,DP));
        ret = max(ret, recr(curr, x, y-1,  matrix,DP));
        return DP[x][y] = ret + 1;
      }
      else{
        return 0; 
      }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      if(matrix.size() == 0) return 0; 
      vector< vector<int> > DP; 
      DP.clear(); 
      DP.resize(matrix.size()); 
      for(int i = 0; i<matrix.size(); i++){
        DP[i].resize(matrix[0].size()); 
        for(int k = 0; k<matrix[i].size(); k++){
          DP[i][k] = -1;
        }
      }

      int out = 0; 
      for(int i = 0; i<matrix.size(); i++){
        for(int k = 0; k<matrix[i].size(); k++){
          out = max(out, recr(-INF, i, k, matrix,DP)); 
        }
      }
      return out; 
    }
};

int main()
{
  Solution s; 


}
