class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int sum = 0; 
      //col 
      for(int i = 0; i<grid.size(); i++){
        //row
        for(int k = 0; k<grid[i].size(); k++){
          //check all 4 sides 
          //make sure we don't go OB
          
          if(grid[i][k] != 1) continue;

          if((k == grid[i].size() - 1) || (grid[i][k+1] == 0)){
            sum++; 
          }
          if((k == 0) || (grid[i][k-1] == 0)){
            sum++; 
          }
          if((i == grid.size() - 1) || (grid[i+1][k] == 0)){
            sum++; 
          }
          if((i == 0) || (grid[i-1][k] == 0)){
            sum++; 
          }
        }
      }
      return sum;
    }
};
