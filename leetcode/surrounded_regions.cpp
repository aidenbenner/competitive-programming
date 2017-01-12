#include <vector> 
#include <unordered_set> 
using namespace std;

class Solution {
  public:
    bool visited[][]; 


    void recur_clear(vector<vector<char>> &board, int x, int y){
      if(board[x][y] == 0){
        board[x][y] = 1; 
        recur_clear(board, x + 1, y); 
        recur_clear(board, x - 1, y); 
        recur_clear(board, x , y +1); 
        recur_clear(board, x , y -1); 
      }
      return; 
    }

    bool check_surround(vector<vector<char>>& board, int x, int y)
    {

      if(x + 1 >= board.size() || x <= -1 || y + 1 >= board[x].size() || y <= -1)
      {
        return false; 
      }
    

      int a = check_surround(board, x + 1, y); 
      a += check_surround(board, x - 1, y); 
      a += check_surround(board, x, y+1); 
      a += check_surround(board, x, y-1); 
      if(a >= 1){
        recur_clear(board,x,y); 
        return true; 
      }
    }

    void solve(vector<vector<char>>& board) {
      visited.erase(); 

      for(int i = 0; i<board.size(); i++){
        for(int k = 0; k<board[i].size(); k++) {

          if(board[i][k] == 0)
          {
            //check if surrounded
            check_surround(board,x,y); 
          }
        }
      }
    }
};
