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

typedef vector<vector<pair<int,int> > > Adjlist;
typedef long long ll;

const long MOD = 1e9 + 7;

long n, k;
int main()
{
    cin >> n >> k;
    vector<int> a; 
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp % 12);
    }

    int out = 0;
    for(int i = 0; i<12; i++){
        vector<bool> x; 
        for(int j = 0; j<n; j++){
            int t = (a[j] + i) % 12 ;
            switch(t) {
                case 0:
                case 4:
                case 7:
                case 10:
                    x.push_back(true);
                    break;
                default:
                    x.push_back(false);
            }
        }

        int l = 0;
        int r = 0;
        int c = k;
        while(r < n){
            out = max(out, r - l);
            r++; 
            if(x[r - 1]){
                continue;
            }
            c--;
            if(c == -1){
                while(x[l]){ 
                    l++;
                }
                l++;
                c++;
            }
        }
        out = max(out, r - l);
    }
    cout << out << endl;
}
