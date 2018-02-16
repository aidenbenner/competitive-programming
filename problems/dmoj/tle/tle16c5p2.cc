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
    long x[12];
    fill(x, x+12, 0);

    vector<int> a;
    for(int i = 0; i<n; i++){
        long tmp;
        cin >> tmp;
        a.push_back(tmp % 12); 
    }

    int offset[] = {0,4,7,10};
    long longest = 0; 
    for(int i = 0; i<n; i++){
        //cout << endl;
        for(int o = 0; o < 4; o++){
            int t = offset[o];
            long curr = 1; 
            int lives = k;
            //cout << endl << i << "   " << o << endl;
            for(int k = i + 1; k<n; k++){
                int z = (a[k] - a[i] + t + 12 * 3) % 12; 
                //cout << z << " "; 
                if(z == 4 || z == 7 || z == 10 || z == 0){
                }
                else {
                    if (lives == 0) {
                        break;
                    }
                    lives--;
                }
                curr++;
            }
            //cout << "curr " << curr << endl;
            longest = max(curr,longest);
        }
        //cout << endl;
        for(int o = 0; o < 4; o++){
            int t = offset[o];
            long curr = 1; 
            int lives = k;
            //cout << endl << i << "   " << o << endl;
            for(int k = i - 1; k>=0; k--){
                int z = (a[k] - a[i] + t + 12 * 3) % 12; 
                //cout << z << " "; 
                if(z == 4 || z == 7 || z == 10 || z == 0){
                }
                else {
                    if (lives == 0) {
                        break;
                    }
                    lives--;
                }
                curr++;
            }
            //cout << "curr " << curr << endl;
            longest = max(curr,longest);
        }
    }
    cout << longest << endl;;
}
