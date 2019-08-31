#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;


#define long long long

vector<int> colors;
vector<vector<int> > edg;

unordered_map<int, long> memo;
long getSumDom(unordered_map<int, long> x, int root) {
  if (memo.count(root)) return memo[root];
  int m = 0;
  int rootc = colors[root];

  int last = -1;
  for (auto c : x) {
    int tmp = c.second;
    if (tmp > m) {
      m = tmp;
    }
  }
  long out = 0;
  for (auto c : x) {
    int tmp = c.second;
    if (tmp == m) {
      out += c.first;
    }
  }

  return memo[root] = out;
}


multiset<int> visited;
unordered_map<int, long> getCols(int x) {
  if (visited.count(x) > 0) return unordered_map<int, long>();
  visited.insert(x);
  unordered_map<int, long> out;
  out[colors[x]] = 1;
  for (auto b : edg[x]) {
    unordered_map<int, long> s = getCols(b);

    if (out.size() < s.size()) {
      std::swap(out, s);
    }

    for (auto p : s) {
      int col = p.first;
      int coun = p.second;
      if (out.count(col)) {
        out[col] = out[col] + coun;
      }
      else {
        out[col] = coun;
      }
    }
  }
  getSumDom(out, x);
  return out;
}

int main() {    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i<n; i++) {
      int x;
      cin >> x;
      colors.push_back(x);
      edg.push_back(vector<int>());
    }

    int root = 0;
    for (int i = 0; i<n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a -= 1;
      b -= 1;
      //if (i == 0)
      //  root = a;
      edg[a].push_back(b);
      edg[b].push_back(a);
    }

    getCols(root);
    unordered_map<int, long> empt;
    for (int i = 0; i<n; i++) {
      cout << getSumDom(empt, i);
      if (i == n - 1) {
        cout << endl;
      }
      else {
        cout << " ";
      }
    }
}
