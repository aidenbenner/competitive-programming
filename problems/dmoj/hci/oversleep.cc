#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>

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

int startX = 0; 
int startY = 0;

int endX = 0; 
int endY = 0;

char board[1001][1001];



int main()
{
    int x,y;
    cin >> x >> y;

    for(int i = 0; i<x; i++){
        for(int k = 0; k<y; k++){
            char tmp; 
            cin >> tmp;
            board[i][k] = tmp;
            if(tmp == 's'){
                startX = i;
                startY = k;
            }
            if(tmp == 'e'){
                endX = i;
                endY = k;
            }
        }
    }

    int cDist = 0; 

    set<pair<int,int> > visited;
    vector<pair<int,int> > curr;
    curr.pb(make_pair(startX, startY));
    vector<pair<int,int> > next;
    while(curr.size() != 0){
        cDist++;
        vector<pair<int,int> > cand;
        while(curr.size() != 0){
            auto z = curr.back();
            if(z.x == endX && z.y == endY) { 
                cout << (cDist - 2) << endl;
                return 0;
            }
            visited.insert(z);
            curr.pop_back();

            cand.push_back(make_pair(z.x - 1, z.y));
            cand.push_back(make_pair(z.x, z.y - 1));
            cand.push_back(make_pair(z.x + 1, z.y));
            cand.push_back(make_pair(z.x, z.y + 1));
        }
        for(auto &i : cand){
            if(i.x < 0 || i.y < 0 || i.x >= x || i.y >= y) continue;
            if(board[i.x][i.y] == 'X') continue;
            if(visited.find(i) != visited.end()) continue;
            curr.push_back(make_pair(i.x, i.y));
        }
    }
    cout << -1 << endl;
}
