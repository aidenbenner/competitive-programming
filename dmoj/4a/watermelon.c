#include <stdio.h>



int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 2; i * i <=n; i += 2){
        if(n % i == 0) {
            int j = n / i;
            if( n % j == 0){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
