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

#define pb push_back
#define x first
#define y second

using namespace std;

typedef vector<vector<pair<int,int> > > Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

int n;


int max_shared(string a, string b){
    for(int i = 0; i<a.size() && i<b.size(); i++){
        if(a[i] != b[i]){
            //cout << a << " " << b << " " << i << endl;
            return i;
        }
    }
    int out = min(b.size() - 1, a.size());
    //cout << a << " " << b << " " << out << endl;
    return out;
}

int g(set<string> &words, string curr) {
    if(words.size() == 0) return 1;
    if(words.size() == 1) return 1+max_shared(*words.begin(), curr);
    auto a = words.upper_bound(curr);
    auto b = a; 
    if(b != words.begin()){
        b--;
    }
    if(a == words.end()){
        a--;
    }
    if(a == words.begin()){
        b++;
    }

    int lower = 1;
    int upper = 1;
    if(a != words.end()){
        upper = 1+max_shared(*a, curr);
    }
    
    if(b != words.end()) {
        lower = 1+max_shared(*b, curr);
    }
    return max(upper, lower);
}

int main()
{
    int c;
    cin >> c;
    for(int i = 0; i<c; i++){
        cin >> n;
        set<string> words;
        int count = 0; 
        for(int k = 0; k<n; k++){
            string s;
            cin >> s;

            //for(auto k : words) cout << k << " "; 
            //cout << "INSERT " << s << endl; 
            int tmp = g(words, s);
            //cout << endl << tmp << endl;
            count += tmp;
            words.insert(s);
        }
        printf("Case #%d: %d\n", i + 1, count);
    }
}
