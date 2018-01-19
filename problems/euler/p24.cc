#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <list>
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

int N; 

map<int, int> f;
int fact(int x){
    if(x <= 0) return 1;
    if(f.find(x) == f.end()) 
        f.insert(make_pair(x, x * fact(x - 1))); 
    return f.at(x);
}


int main()
{
    // int k = 1000000;
    int k = 1234321543;

    list<int> used; 
    for(int i = 0; i<10; i++){
        used.push_back(i); 
    }

    int count = 0; 
    int ind = 0; 
    int currCount = 0; 

    printf("%d\n", count); 
    vector<int> out; 
    while(count != k || ind != 10){
        int currCount = 0; 
        int newCount = count + currCount * fact(10 - ind - 1);
        printf("%d\n", ind); 
        while(newCount <= k){
            currCount++; 
            newCount = count + currCount * fact(10 - ind - 1);
        }
        currCount--; 
        count = count + currCount * fact(10 - ind - 1);
        ind++; 

        auto itr = used.begin(); 
        printf("cc %d\n", currCount); 
        while(currCount--){
            itr++; 
        }
        auto val = *itr;
        printf("v %d\n", val); 
        out.push_back(val); 
        used.remove(val); 
        printf("%d\n", count); 
    }
    for(int i = 0; i<out.size(); i++){
        printf("%d", out[i]); 
    }
}

