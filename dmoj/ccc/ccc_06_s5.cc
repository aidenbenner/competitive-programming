#include <iostream>

  int A,B,C; 
bool origin(vector<vector<int>> board)
{

}

int main()
{
  cin >> A >> B >> C; 
  int Row, Col; 
  cin >> Row >> Col; 

  vector<vector<int>> board;
  board.resize(Row);
  for(int i = 0; i<Row; i++){
    board[i].resize(Col);
    for(int k = 0; k<Col; k++){
      cin >> board[i][k]; 
    }
  }


}

