#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

const int lim = 10000000;

ll DP[lim]; 
ll fib(int n){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(DP[n] != -1) return DP[n];

    return DP[n] = fib(n - 1) + fib(n - 2); 
}

int numDig(ll in){
    int dig = 0; 
    while(in != 0 ){
        in /= 10; 
        dig++; 
    }
    return dig; 
}


int N; 
int main()
{
    fib(lim); 
    for(int i = 0; i<lim; i++){
        DP[i] = -1; 
    }
    DP[0] = 1; 
    fib(1000); 
    int lastDig = 0; 
    int count = 0; 

    int x = 1e7; 
    int digc[x]; 

    for(int i = 0; i<x; i++){
        digc[i] = 0; 
    }

    for(int i = 0; i<1000; i++){
        int dig = numDig(fib(i));
        digc[dig]++; 
        count++; 
    }

    for(int i = 0; i<x; i++){
        printf("%d", i); 
        if(digc[i]){
            printf("%d %d\n", i, digc[i]); 
        }
    }
}
