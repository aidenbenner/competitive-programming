
#include <bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;

vector < ull > pythagoreanTriple(ull a){
  vector<ull> out;
  if(a % 2 == 1){
    ull k = (a - 1) / 2;
    ull m = k + 1; 
    ull n = k; 

    ull b= 2 * m * n;
    ull c = m * m + n * n;

    out.push_back(a); 
    out.push_back(b); 
    out.push_back(c); 
  }
  else{
    ull m = a / 2; 
    ull n = 1; 

    out.push_back(2 * n * m);
    out.push_back(m * m - n * n);
    out.push_back(m * m + n * n); 
  }

  return out;
}

int main() {
    int a;
    cin >> a;
    vector < ull > triple = pythagoreanTriple(a);
    for (ssize_t i = 0; i < triple.size(); i++) {
        cout << triple[i] << (i != triple.size() - 1 ? " " : "");
    }
    cout << endl;
    

    return 0;
}

