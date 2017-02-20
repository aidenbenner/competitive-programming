#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;

struct Sub{
  string *str; 
  int a; 
  int b; 
   bool operator< (const Sub &j) { 
     return str->substr(a, b) < str->substr(j.a, j.b);
   }
};


int main()
{
  int N; 
  cin >> N;
  while(N--){
    string str;
    cin >> str;

    set<string> out; 
    int num = 1;
    for(int k = 1; k<=str.size(); k++){
      for(int i = 0; i<str.size(); i++){
        if(i + k > str.size()) break;
        out.insert(str.substr(i,k)); 
      }
      num += out.size(); 
      out.clear(); 
    }

    cout << num << endl;

  }
}
