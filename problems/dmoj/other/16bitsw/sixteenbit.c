#include <stdio.h>


int main(void){
    int n;
    scanf("%d", &n);
    
    while(n--){
        long a, b, p;
        scanf("%ld %ld %ld", &a, &b, &p);

        if(a * b != p){
            printf("16 BIT S/W ONLY\n");
        }
        else {
            printf("POSSIBLE DOUBLE SIGMA\n");
        }
    }
}
