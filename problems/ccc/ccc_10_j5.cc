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

typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vector<pair<int,int> > > Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

bool valid(int a, int b){
    return a >= 0 && b >= 0  && a < 1000 && b < 1000;
}

int main()
{
    int sx, sy, ex, ey; 
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    if(sx == ex && sx == ey) {
        cout << 0 << endl;
        return 0;
    }

    set<pi> visited;
    vpi curr; 
    curr.pb(make_pair(sx, sy));
    int cDist = -1; 
    while(curr.size() != 0){
        vpi next; 
        cDist++; 
        for(auto c : curr) {
            if(!valid(c.x, c.y)) continue;
            if(visited.find(c) != visited.end())  continue;
            if(c.x == ex && c.y == ey){
                cout << cDist << endl;
                return 0;
            }
            visited.insert(c);
            next.push_back(make_pair(c.x + 2, c.y + 1));
            next.push_back(make_pair(c.x + 2, c.y - 1));
            next.push_back(make_pair(c.x - 2, c.y + 1));
            next.push_back(make_pair(c.x - 2, c.y - 1));
            next.push_back(make_pair(c.x + 1, c.y + 2));
            next.push_back(make_pair(c.x - 1, c.y + 2));
            next.push_back(make_pair(c.x + 1, c.y - 2));
            next.push_back(make_pair(c.x - 1, c.y - 2));
        }
        curr = next;
    }
}
