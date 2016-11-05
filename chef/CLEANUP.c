#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);

    while(n--){
        int a,b;
        scanf("%d %d",&a,&b);
        
        int jobs[a]; 
        for(int i = 0; i<a; i++){
            jobs[i] = 0;
        }
        int ind;
        for(int i = 0; i<b; i++){
           scanf("%d", &ind); 
           jobs[ind-1] = 1;
        };
        
        //print chef
        for(int k = 0; k<a; k += 2){
            if(!jobs[k]){
                printf("%d ", k + 1);
            }
        }
        printf("\n");
        for(int k = 1; k<a; k += 2){
            if(!jobs[k]){
                printf("%d ", k + 1);
            }
        }
        printf("\n");
    }
}
