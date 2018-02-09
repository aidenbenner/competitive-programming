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

int n; 
int main()
{
    scanf("%d", &n); 
    int out = 0; 
    while(n > 1){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                int a = n / i;
                n -= a;
                out += n / a;
                i = 1; 
            }
        }
        if(n != 1){
            n -= 1;
            out += n;
        }
    }
    printf("%d", out);
}
