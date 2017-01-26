#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;
class Solution {
  public:

    void clear_vec(vector<bool> &nums){
      for(int i = 0; i<nums.size(); i++){
        nums[i] = false; 
      }
    }


    bool isSolved(vector<vector<int> > board)
    {
      //row
      vector<bool> nums; 
      nums.resize(10); 
      clear_vec(nums); 


      for(int i = 0; i<board.size(); i++){
        clear_vec(nums); 
        for(int k = 0; k<board[i].size(); k++){
          int val = board[i][k]; 
          if(val == 0){
            continue;
          }
          if(nums[val]){
            return false;
          }
          nums[val] = true;
        }
      }

      for(int i = 0; i<board.size(); i++){
        clear_vec(nums); 
        for(int k = 0; k<board[i].size(); k++){
          int val = board[k][i]; 
          if(val == 0){
            continue;
          }
          if(nums[val]){
            return false;
          }
          nums[val] = true;
        }
      }

      //for each box
      for(int i = 0; i<board.size(); i++){
        clear_vec(nums); 
        for(int k = 0; k<board[i].size(); k++){
          // x = i % 3 * 3.. y = i / 3
          int val = board[(i / 3) * 3 + (k/3)][(i % 3 * 3) + (k % 3) ]; 
          if(val == 0){
            continue;
          }
          if(nums[val]){
            return false;
          }
          nums[val] = true;
        }
      }
      return true;
    }

    bool solve(vector<vector<int> >& state)
    {
      bool solved = isSolved(state); 

      //can't keep going down this line
      if(!solved){
        return false; 
      }

      for(int i = 0; i<state.size(); i++){
        for(int k = 0; k<state.size(); k++){
          if(state[i][k] == 0){
            for(int z = 1; z<=9; z++){
              state[i][k] = z; 

              if(solve(state)){
                return true;
              } 
              else{
                state[i][k] = 0; 
              }
            }

            if(state[i][k] == 0){
              return false;
            }
          }
        }
      }
      return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
      vector<vector<int> > iboard; 
      iboard.resize(9); 
      for(int i = 0; i<board.size(); i++){
        iboard[i].resize(9); 
        for(int k = 0; k<board.size(); k++){
          if(board[i][k] == '.'){
            iboard[i][k] = 0;
            continue;
          }
          iboard[i][k] =  board[i][k] - '0';
        }
      }
      solve(iboard); 
      for(int i = 0; i<board.size(); i++){
        for(int k = 0; k<board.size(); k++){
          board[i][k] = (char)(iboard[i][k] + '0'); 
        }
      }
    }
};
