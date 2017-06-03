#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#define abs(x) x < 0 ? -x : x

using namespace std;

typedef struct { 
    int a;
    int b;
} pair; 


pair MEMO[] ; 

int inversions = 0; 
int getNumInversions(int bot, int top,  int goal[], int n){
    int num = top - bot + 2; 
    if(num-1 == n){
        return 0; 
    }
    if(bot > 0 && goal[bot-1] == num){
        return getNumInversions(bot - 1, top, goal, n);  
    }
    else if(top < n-1 && goal[top+1] == num){
        return getNumInversions(bot, top+1, goal, n);  
    }
    return 1 + min(getNumInversions(bot, top+1, goal, n),  getNumInversions(bot - 1, top, goal, n));
}


int main(void){
	//read 
	int n;
	scanf("%d", &n);
    vector<int> curr(n); 

    int goal[n]; 
    int start = 0; 
    for(int i = 0; i<n; i++){
        scanf("%d", &goal[i]); 
        if(goal[i] == 1){
            start = i; 
        }
    }

    //naive 


	//soln
}
