#include <stdio.h>



int main(void){
    int roll ;
    scanf("%d", &roll);

    int position = 1;
    while(roll != 0){
        if(position + roll <= 100){
            position += roll;
        }

        switch(position){
            case 54: position = 19; break;
            case 90: position = 48; break;
            case 99: position = 77; break;
            case 9: position = 34; break;
            case 40: position = 64; break;
            case 67: position = 86; break;
        }


        printf("You are now on square %d\n", position);
        if(position == 100){
            printf("You Win!\n");
            return 0;
        }
        scanf("%d", &roll);
    }
    if(position == 100){
        printf("You Win!\n");
    }
    else{
        printf("You Quit!\n");
    }

}
