#include <stdio.h>



int main(){
    int l, d;
    scanf("%d %d", &d, &l);

    printf("Sun Mon Tue Wed Thr Fri Sat\n");
    //offset 
    for(int i = 0; i<(d-1) * 4; i++){
       printf(" "); 
    }

    int currDay = 0; 
    int dayOfWeek = d;
    for(int i = 0; i<l; ++i){
        ++currDay;
        if(dayOfWeek % 7 == 1){
            printf("\n");
        }
        ++dayOfWeek;
        printf("%3d ",  currDay);
    }
}
