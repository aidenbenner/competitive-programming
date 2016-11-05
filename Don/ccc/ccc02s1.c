#include <stdio.h>


int main(void){
    int totalCombs = 0;
    int min = 99999999;
    int p,g,r,o,n;
    scanf("%d %d %d %d %d", &p, &g, &r, &o, &n);
    for(int i = 0; i * p <= n; i++){
        int ptick = i * p;
        for(int k = 0;  ptick + k * g <= n; k++){
            int gtick = k * g; 
            for(int j = 0; j * r + ptick + gtick <= n; j++){
                int rtick = j * r;
                for(int m = 0; m * o + ptick + gtick + rtick<= n; m++){
                    if(m * o + ptick + gtick + rtick == n){
                        if( i + k + j + m < min){
                            min = i + k + j  + m;
                        }
                        printf("# of PINK is %d ", i);
                        printf("# of GREEN is %d ", k);
                        printf("# of RED is %d ", j);
                        printf("# of ORANGE is %d ", m);
                        totalCombs++;
                        printf("\n");
                    }
                }
            }
        }
    }
    printf("Total combinations is %d.\n", totalCombs);
    printf("Minimum number of tickets to print is %d.", min);
}
