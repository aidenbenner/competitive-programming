#include <stdio.h>
#define INF                         (int)1e9

int MEMO[5681]; 


int getDistance(int dist, int clubs[], int n, long moves){
    if(MEMO[dist] != -1){
        return MEMO[dist]; 
    }
    printf(" %d %d %d \n", dist, n, moves);
    
    if(dist == 0){
        return moves; 
    }

    long minMoves = INF; 
    for(int i = 0; i<n; i++){
        if(dist - clubs[i] < 0){
            continue;
        }
        long curr = getDistance(dist - clubs[i], clubs, n, moves+1);
        if(curr < minMoves){
            minMoves = curr;
        }
    }
    MEMO[dist] = minMoves; 
    return MEMO[dist]; 
}

int main(void){
    for(int i = 0; i<5681; i++){
        MEMO[i] = -1; 
    }
    
    int dist, nClub; 
    scanf("%d %d", &dist, &nClub);
    
    int clubs[nClub];
    for(int i = 0; i<nClub; i++){
        scanf("%d", &clubs[i]);
    }

    int n = getDistance(dist, clubs, nClub, 0);
    if(n == INF || n == -1){
        printf("Roberta acknowledges defeat.\n");
    }
    else{
        n = n % 10;
        printf("Roberta wins in %d strokes.\n",n);
    }
}
