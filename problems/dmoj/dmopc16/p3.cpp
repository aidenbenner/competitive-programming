#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#define abs(x) x < 0 ? -x : x

typedef long long ll; 
using namespace std;

typedef struct {
    ll m;
    ll b;
} Line;

bool sortLine(Line a, Line b){
    if(a.m < b.m){
        return true; 
    }
    else {
        return false; 
    }
}

int main(void){
	//read 
	ll n;
	scanf("%lld", &n);

    Line lines[n];
    for(long i = 0; i<n; i++){
        scanf("%lld %lld", &lines[i].m, &lines[i].b);
    }


    std::sort( lines, lines+n, sortLine );

    ll linesN = 1; 
    ll inters = 0; 
    ll parStreak = 0;
    for(long i = 1; i<n; i++){
        //check if parallel
        if(lines[i].m == lines[i-1].m){
            if(lines[i].b == lines[i-1].b){
                printf("Infinity\n");
                return 0;
            }
            parStreak++; 
            inters += (linesN - parStreak); 
            linesN++;
        }
        else{
            parStreak = 0; 
            inters += linesN;
            linesN++;
        }
    }
    printf("%lld", inters);
}
