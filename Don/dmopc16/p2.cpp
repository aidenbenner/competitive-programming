
#include <cstdio>
#include <cmath>
#include <iostream>
#define abs(x) x < 0 ? -x : x

using namespace std;

int main(void){
	//read 
	int n;
	scanf("%d", &n);

    int num[n]; 
    int count = 0;
    int first;
    for(int i = 0; i<n; i++){
        scanf("%d", &first);
        if(first % 2 == i % 2){
            count++;
        }
    }
    printf("%d",count);

	//print
}
