#include<stdio.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}



int main(void){
    int n,d;
    scanf("%d %d", &n, &d);
    
    int gcdN = gcd(n,d);

    int full = n/d; 
    n = n - full * d;
    n = n / gcdN;
    d = d / gcdN;

    
    if(full != 0){
        if(n == 0){
            printf("%d\n", full);
            return 0;
        }
        printf("%d %d/%d\n", full, n,  d);
    }
    else if(d == 1){
        printf("%d\n", full);
    }
    else if(n == 0){
        printf("%d\n", full);
    }
    else{
        printf("%d/%d\n", n, d);
    }
}
