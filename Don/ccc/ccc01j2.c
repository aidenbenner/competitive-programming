#include <stdio.h>

int main(){
    int x,m,n;
    scanf("%d %d", &x, &m);

    for(int i = 0; i<m; i++){
        n = i;
        if((x*n)%m==1){
            printf("%d",n);
            return 0;
        }
    }
    printf("No such integer exists.");
}
