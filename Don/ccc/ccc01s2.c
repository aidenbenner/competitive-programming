#include <stdio.h>
#include <math.h>

int rowNum(int layer){
    int num = 4;
    for(int i = 1; i<=layer; i++){
        num = 3 * num + 4;
    }
    return num ;
}

typedef struct {
    int a;
    int b;
} Pair;
Pair nextMove(int last, int row, int col, int board[], int n){
    Pair p = { 0 , 0 };
    //last  
    // R = 0, D = 1, L = 2, U = 3
    if(last == 0){
        //check if next square is open or at max
        if(col == n - 2 ){
            p.a = row - 1;
            p.b = col;
            return p;
        }
        if(board[row][col + 1] == -1){
            p.a = row - 1;
            p.b = col;
            return p;
        }
        else{
            p.a = row;
            p.b = col + 1;
            return p;
        }
    }
    if(last == 1){
        if(row == n - 2){
            p.a = row;
            p.b = col - 1;
            return p; 
        }

    }

}


int main(void){
    int a, b; 
    scanf("%d %d", &a, &b);

    int range = a-b; 
    int n = sqrt(range) + 1; 

    int board[n][n]; 
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            board[k][i] = -1;
        }
    }

    int offset = rowNum(n) - range;
    int charNum = 0;

    for(int i = 0; i<range; i++){
        //move right 
    }

    //print spaces from offset

}
