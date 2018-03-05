#include <iostream>
#include <algorithm>
#include <string> 
#include <cassert> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define INF 1e9
#define EPS 1e-9

#define pb push_back
#define x first
#define y second

using namespace std;

typedef vector<vector<pair<int,int> > > Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

vector<string> lg; 
map<string, int> mp;

const int MAX_MOD = 1000007;
ull COUNT[MAX_MOD];
ull SIZE[MAX_MOD];
string CHECK[MAX_MOD];

int hashc(char s, long old) {
    return ((int)s + old * 259) % MAX_MOD;
}

void e(string& s, long hs, int k, int i) {
    if(k - i >= 0 && k + i + 1 < s.size())
    if(s[k - i] == s[k + i + 1]) {
        hs = hashc(s[k + i + 1], hs);
        e(s, hs, k, i + 1);
        while(SIZE[hs] != 0 && i * 2 + 2 != SIZE[hs]) {
            hs++; 
            hs = hs % MAX_MOD;
        }
        COUNT[hs]++;
        SIZE[hs] = (i * 2 + 2);
        return;
    }
}

void f(string& s, long hs, int k, int i) {
    if(k - i >= 0 && k + i < s.size()) 
    if(s[k - i] == s[k + i]) {
        hs = hashc(s[k + i], hs);
        f(s, hs, k, i + 1);
        while(SIZE[hs] != 0 && i * 2 + 1 != SIZE[hs]) {
            hs++; 
            hs = hs % MAX_MOD;
        }
        COUNT[hs]++;
        SIZE[hs] = (i * 2 + 1);
        return;
    }
}

int main()
{
    std::fill(COUNT, COUNT + MAX_MOD, 0);
    std::fill(SIZE, SIZE + MAX_MOD, 0);
    std::fill(CHECK, CHECK + MAX_MOD, "");
    string s;
    cin >> s;
    for(int i = 0; i<s.size(); i++){
        f(s, 0, i, 0); 
        e(s, 142426, i, 0); 
    }

    ull o = 0;
    for(int i = 0; i<MAX_MOD; i++){
        o = max(o, COUNT[i] * SIZE[i]);
    }
    cout << o << endl;
}
