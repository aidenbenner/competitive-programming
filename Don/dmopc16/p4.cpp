#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double MEMO[10000];

double min3(double a, double b, double c){
    return min(a, min(b,c));
}

double getMinCost(int index, double shoes[]){
    if(MEMO[index] != -1){
        return MEMO[index]; 
    }
    if(index == 0){
        MEMO[index] = shoes[0]; 
        return MEMO[index];
    }
    if(index == 1){
        MEMO[index] = shoes[0] + shoes[1] - 0.5 * min(shoes[0], shoes[1]);
        return MEMO[index];
    }
    /*
    if(index == 2){
        MEMO[index] = shoes[index - 1]  + shoes[index] + shoes[index-2] - min3(shoes[index-1], shoes[index-2], shoes[index]);
        return MEMO[index];
    }*/

    double costWith2G = shoes[index] + shoes[index-1] - 0.5 * min(shoes[index], shoes[index-1]);
    double costWith3G = shoes[index] + shoes[index - 1]  + shoes[index-2] - min3(shoes[index-1], shoes[index-2], shoes[index]) ;

    MEMO[index] = min3(getMinCost(index-1, shoes) + shoes[index], getMinCost(index-2, shoes) + costWith2G, getMinCost(index-3, shoes) + costWith3G );
    return MEMO[index];
}

int main(void){
    for(int i = 0; i<10000; i++){
        MEMO[i] = -1; 
    }
	//read 
	int n;
	scanf("%d", &n);

    double shoes[n];
    for(int i = 0; i<n; i++){
        scanf("%lf", &shoes[i]);
    }
     printf("%.1lf\n", getMinCost(n-1,shoes));
}
