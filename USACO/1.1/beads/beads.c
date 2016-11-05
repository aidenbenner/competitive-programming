/* 
ID: aiden.b1
TASK: beads
LANG: C
*/

#include <stdio.h>
#include <stdbool.h>

#define DEBUG 1
#ifdef DEBUG
#define DEBUG_PRINT printf 
#else
#define DEBUG_PRINT(...) 
#endif

int getNumBeads(char *beads, int size, int loc){
    //go forward
    DEBUG_PRINT("size %d  loc %d \n", size, loc);
    int fwd = 1;
    char last = beads[loc];
    int i = 1; 
    int nextInd = (loc + i) % size;
    while( last == beads[nextInd] ) {
        DEBUG_PRINT("next ind %d \t fwd %d \t \n",nextInd, fwd);
        nextInd = (loc + i) % size;
        fwd++; 
        i++;
    }

    int bw = 1;
    i = 1;
    last = beads[loc - 1];
    nextInd = (loc - i) % size;
    while( last == beads[nextInd] ) {
        DEBUG_PRINT("next ind %d \t bw %d \t \n",nextInd, bw);
        nextInd = (loc - i) % size;
        bw++; 
        i++;
    }


    return bw + fwd;
}


int main(void){
    FILE *fin = fopen("beads.in","r");
    FILE *fout = fopen("beads.out","w");

    int n ;
    fscanf(fin,"%d",&n);
    char beads[n];
    fscanf(fin,"%s",beads);
    
    int max = 0;
    int maxLoc = 0; 

    for(int i = 0; i<n; i++){
        int curr = getNumBeads(beads,n,i);
        
        if( curr > max){
            max = curr;
            maxLoc = i;
        }
    }


    printf("%d", maxLoc);    
    return 0;
}
