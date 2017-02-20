#include <stdio.h>
#include <stdbool.h>


bool canVote(int y, int m, int d){
    if(y<1989) return true;
    if(y>1989) return false;
    if(m < 2) return true;
    if(m > 2) return false;
    if(d <= 27) return true;
    return false;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        int result = canVote(a,b,c);
        if(result == true){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
