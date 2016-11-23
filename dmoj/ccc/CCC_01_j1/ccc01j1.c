#include <stdio.h>


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int numS = 1 + 2 * i;
        if(i > n/2){
            numS = n - 2 * (i - n/2);
        }
        for(int k = 0; k<numS; k++){
            printf("*");
        }
        for(int k = 0; k< 2 * n - 2 * numS; k++){
            printf(" ");
        }
        for(int k = 0; k<numS; k++){
            printf("*");
        }printf("\n");
    }

}
