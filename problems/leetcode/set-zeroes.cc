#include <iostream>
#define INF 1e9 


class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      for(int i = 0; i<matrix.size(); i++){
        for(int k = 0; k<matrix[i].size(); k++){
          if(matrix[i][k] == 0){
            for(int z = 0; z<matrix[i].size(); z++){
              if(matrix[i][z] != 0){
                matrix[i][z] = INF; 
              }
            }

            for(int z = 0; z<matrix.size(); z++){
              if(matrix[z][k] != 0){
                matrix[z][k] = INF; 
              }
    
            }
          }
        }
      }
      for(int i = 0; i<matrix.size(); i++){
        for(int k = 0; k<matrix[i].size(); k++){
          if(matrix[i][k] == INF){
            matrix[i][k] = 0; 
          }
        }
      }
    };

};
