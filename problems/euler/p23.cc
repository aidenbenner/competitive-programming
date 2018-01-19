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

/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

bool isAbund[28125]; 
long sumProper(int x){
    long out = 0; 
    // printf("\n%d ", x); 
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            // printf(" %d %d ", i, x / i); 
            out += i + (x / i); 
            if(i == x / i) 
                out -= i; 
        }
    }
    return out;
}

bool isNotSA(int x){
    for(int i = 1; i<x; i++){
        if(isAbund[i] && isAbund[x - i]){
            // printf("%d = %d + %d \n", x, i, x - i);
            return false;
        }
    }
    return true;
}

int main()
{
    int upperLim = 28123;
    for(int i = 1; i<upperLim; i++){
        if(sumProper(i) > i){
            isAbund[i] = true; 
        }
        else{
            isAbund[i] = false; 
        }
    }

    long out = 0; 
    for(int i = 1; i<upperLim; i++){
        if(isNotSA(i)){
            out += i; 
        }
    }

    printf("%ld", out); 
}
