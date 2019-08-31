#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool board[1001][1001];
long memo[1001][1001];
int visited[1001][1001];

int pxx[1001][1001];
int pyy[1001][1001];

int n, m, k;


void memoize(int x, int y, long  result) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (!board[x][y]) return;
    if (visited[x][y] == 2) return;
    visited[x][y] = 2;
    if (memo[x][y] < result) {
        memo[x][y] = result;
    }
    memoize(x + 1, y, result);
    memoize(x, y + 1, result);
    memoize(x - 1, y, result);
    memoize(x, y - 1, result);
}

long solve(int x, int y, int px, int py) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (!board[x][y]) return 0;
    // if (memo[x][y] != -1) return memo[x][y];
    if (pxx[x][y] != 0) {
        int k = memo[pxx[x][y]][pyy[x][y]];
        if (k != -1) {
            return k;
        }
    }
    if (visited[x][y] != 0) return 0;
    visited[x][y] = 1;
    pxx[x][y] = px;
    pyy[x][y] = py;


    // cout << "hit" << endl;

    int out = 0;
    if (board[x + 1][y]) {
        out += solve(x+1,y, px, py);
    }
    else {
        out++;
    }
    if (board[x][y + 1]) {
        out += solve(x,y+1, px, py);
    }
    else {
        out++;
    }
    if (board[x - 1][y]) {
        out += solve(x-1,y, px, py);
    }
    else {
        out++;
    }
    if (board[x][y - 1]) {
        out += solve(x,y-1, px, py);
    }
    else {
        out++;
    }
    return memo[x][y] = out;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int k = 0; k < m; k++) {
            board[i][k] = (bool)(s[k] == '.');
            memo[i][k] = -1;
            //cout << board[i][k];
        }
        // cout << endl;
    }

    while(k--) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        long result = solve(a,b, a, b);
        cout << result << endl;
        // cout << a << b <<endl;
        // memoize(a,b, result);
    }
}
