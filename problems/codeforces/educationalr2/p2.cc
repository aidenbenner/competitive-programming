#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i<n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i<m; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }

  sort(a.begin(), a.end());


  for (int i = 0; i<m; i++) {
    auto itr = upper_bound(a.begin(), a.end(), b[i]);
    cout << itr - a.begin() << " ";
  }
  cout << endl;
}
