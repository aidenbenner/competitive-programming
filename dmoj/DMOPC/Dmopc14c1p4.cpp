#include <cstdio>

int main(void){
    int n, ap,bp,cp;
    scanf("%d %d %d %d", &n, &ap, &bp, &cp);
   
    int machine = 0;
    int choice; 
    int count = n; 
    int total = 0;
    while(count > 0){
        choice = machine % 3; 
        total++; 
        if(choice == 0){
            ap++;
            if(ap % 35 == 0){
                count += 30;
            }
            count --; 
        }
        else if(choice == 1){
            bp++;
            if(bp % 100 == 0){
                count += 60;
            }
            count--; 
        }
        else{
            cp++;
            if(cp % 10 == 0){
                count += 9;
            }
            count--;
        }
        machine++; 
    }
    printf("Martha plays %d times before going broke.\n", total);
}
