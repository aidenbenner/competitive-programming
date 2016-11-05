/*
 ID: aiden.b1
 LANG: C
 TASK: friday 
 *
 */ 
#include <stdio.h>
#include <stdbool.h>

int main(){
    FILE *fin = fopen("friday.in", "r");
    FILE *fout= fopen("friday.out", "w");
    
    int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int days[7]; 
    for(int i = 0; i<7; i++){
        days[i] = 0;
    }

    int n; 
    fscanf(fin,"%d",&n);
    //jan 1st 1900 to dec 31 1900+n-1
    
    bool isLeap = false;
    int dayCounter = 1; 
    for(int i = 1900; i<1900+n; i++){
        if(i % 4 == 0 & i % 100 != 0){
            isLeap = true;
        }
        else{
            if(i % 400 == 0){
                isLeap = true;
            }
            else{
                isLeap = false;
            }
        }

        for(int i = 0; i<12; i++){
            //foreach month
           int monthDays = months[i]; 
           if(i == 1 && isLeap){
                monthDays = 29;
           }
           dayCounter += 13;
           dayCounter = dayCounter % 7;
           days[dayCounter]++;
           dayCounter += monthDays - 13; 

        }
        //check if leap year 
    }

    for(int i = 0; i<6; i++){
        fprintf(fout, "%d ", days[i]);
    }
    fprintf(fout, "%d\n", days[6]);
}
