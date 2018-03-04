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

#define DEBUG 1
#ifdef DEBUG
# define DBG(x) printf x
#else
# define DBG(x) do {} while (0)
#endif

using namespace std;

typedef vector<vector<pair<int,int> > > Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

int N, A, C;

void mergeInter(list<pair<int,int> > &a){
    // merge overlapping intervals
    vector<pair<int,int> > out;
    for(int i = 0; i<a.size() - 1; i++){
        if(a[i].second > a[i + 1].first){
            out.push_back(make_pair(a[i].first, max(a[i].second, a[i + 1].second)));
            i--; 
        }
        else out.push_back(a[i]);
    }
    a.resize(out.size());
    for(int i = 0; i<a.size(); i++){
        a[i] = out[i];
        DBG(("i %d %d %d\n", i, a[i].first, a[i].second));
    }
}

int binSearchStart(vector<pair<int,int> > &a, int k) {
    int bot = 0;
    int top = a.size() - 1;
    while(bot < top){
        int mid = bot +  (top - bot) / 2; 
        if(a[mid].first == k){
            return mid;
        }
        if(a[mid].first < k)
            bot = mid;
        else 
            top = mid;

    }
    return bot;
}
// C
// 1 3
// 4 6
// A
// 1 2

int check(vector<pair<int,int> > &a, int start, int end){
    int k = binSearchStart(a, start);
    int m = binSearchStart(a, end);
    printf("start: %d end: %d k: %d m: %d\n", start,end,k,m);
    // all after k start 
    int diff = end - start;
    for(int i = k; k<=m; k++){
        // exclude vals in this commitment range
        int s = max(a[i].first, start);
        int e = min(a[i].second, end);
        diff -= (e - s);
    }
    return diff;
}

int main()
{
    cin >> N >> A >> C;
    vector<pair<int,int> > a;
    for(int i = 0; i<A; i++){
        int tmpA, tmpB; 
        cin >> tmpA >> tmpB;
        a.push_back(make_pair(tmpA, tmpB));
    }
    vector<pair<int,int> > c;
    for(int i = 0; i<C; i++){
        int tmpA, tmpB; 
        cin >> tmpA >> tmpB;
        c.push_back(make_pair(tmpA, tmpB));
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    mergeInter(a);
    mergeInter(c);

    int out = 0; 
    for(int i = 0; i<a.size(); i++){
        check(c, a[i].first, a[i].second);
    }
    
    cout << out << endl;

