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

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9 + 7;

class Solution {
public:
    string longestPalindrome(string s) {
       if(s.length() == 0) return ""; 

      int longest = 0; 
      string out = ""; 
      out.push_back(s[0]);
      for(int i = 0; i<s.length(); i++){
        for(int k = s.length() - 1; k>= i + 1; k--){
          if(k - i < longest) break;
          bool isPalin = true;
          for(int j = 0; j < k - i + 1; j++){
            if(s[i + j] != s[k - j]){
              isPalin = false;
            }
          }
          if(isPalin){
            if(k - i > longest){
              out = s.substr(i, k - i + 1); 
              longest =  k - i;
              break;
            }
          }
        }
      }
        return out; 
    }
};

int main() {
  Solution s;
  string c; 
  cin >> c;
  cout << (s.longestPalindrome(c)) << endl;
}
