#include <stdio.h>


int main(void){
    int n; 
    //read 32 bit number
    scanf("%d", &n);
    while(n--){
        int k; 
        scanf("%xd", &k);

        //test if affect
        int h = k >> 20; 
        if(!(h & 1)){
            printf("%08X\n", k);
        }
        else { 
            int a20 = 1 << 20; 
            printf("%08X ", a20 ^ k);
            printf("%08X\n", k);
        }
    }
}
