#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int n;

int main() {
    vector<pair<vector<int>, int>> mp;
    map<int, vector<int>> dup; 
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            auto p = pair<vector<int>, int>();
            p.y = i;
            mp.push_back(p);
            for (int k = 0; k < 5; ++k) {
                int x; 
                scanf("%d", &x);
                mp.back().x.pb(x);

                if (dup.find(x) == dup.end()) {
                    dup[x] = vector<int>();
                }
                dup[x].push_back(mp.size() - 1);
            }
            sort(mp.back().x.begin(), mp.back().x.end());
        }
    }



    int cardA = 420;
    int cardB = 420;

    for (auto c : dup) {
        sort(c.y.begin(), c.y.end());
        cout << c.x << endl;
        for (auto z : c.y) {
            cout << "\t" << z << endl;
        }
    }

    /*
    sort(mp.begin(), mp.end(), 
            [](pair<vector<int>, int> a, pair<vector<int>, int> b) {
                for (int i = 0; i < 5; i++) {
                    if (a.x[i] < b.x[i]) {
                        return true;
                    }
                    else if (a.x[i] > b.x[i]) {
                        return false;
                    }
                }
                return a.y < b.y;
            });*/

    for (int i = 0; i < mp.size(); ++i) {
        for (int j = i + 1; j < mp.size(); ++j) {
            if (mp[i].y == mp[j].y) continue;
            set<int> s; 
            set<int> shared; 
            int uniq = 5;
            for (int k = 0; k < 5; k++) {
                s.insert(mp[i].x[k]);
            }
            for (int l = 0; l < 5; l++) {
                int z = mp[j].x[l];
                if (s.count(z) == 0) {
                    s.insert(z);
                }
                else {
                    shared.insert(z);
                }
            }
            if (shared.size() == 0) {
                continue;
            }

            set<int> cardShare;
            for (int last : shared) {
                bool tie = true;
                for (int curr : s) {
                    if(last == curr) continue;
                    for (int r : dup[curr]) {
                        if (r == i || r == j) {
                            continue;
                        }
                        cardShare.insert(r);
                    }
                }
                for (int zz : cardShare) {
                    if (cardShare.count(zz) >= 5) {
                        tie = false;
                        break;
                    }
                }
                if (tie) {
                    int a = mp[i].y;
                    int b = mp[j].y;
                    cout << i << "W" << j;
                    if (a < cardA) {
                        cardA = a;
                        cardB = b;
                    }
                    else if(a == cardA) {
                        cardB = min(b, cardB);
                    }
                    break;
                }
            }
        }
    }

    if (cardA == 420) {
        cout << "no ties" << endl;
    }
    else {
        cout << cardA << " " << cardB << endl;
    }
}

