#include <stdio.h>


int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    int out = a - b ; 
    if(out % 10 == 9 ) {
        out--; 
    }
    else{
        out++;
    }
    printf("%d", out);
    return 0;
}
