#include <cstdio>
#include <cmath>
#include <iostream>
#define abs(x) x < 0 ? -x : x

using namespace std;

int main(void){

	//read 
	int n, b;
	scanf("%d %d", &n, &b);

    if(b >= 95 && n == 3){
        printf("C.C. is absolutely satisfied with her pizza.\n");  
    }
    else if(b <= 50 && n == 1){
        printf("C.C. is fairly satisfied with her pizza.\n");  
    }
    else{
        printf("C.C. is very satisfied with her pizza.\n");  
    }

}
