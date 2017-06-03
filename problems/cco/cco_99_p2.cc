
#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>

#define INF 1e9
#define EPS 1e-9
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;



int N; 
int main()
{
  cin >> N;
  while(N--)
  {
    multiset<string> set; 
    vector<string> strs;

    int W, F;
    cin >> W >> F;

    string str;
    for(int i=0;i<W;i++){
      cin >> str;
      if(set.count(str) == 0){
        strs.pb(str);
      }
      set.insert(str);
    }
    
    sort(strs.begin(), strs.end(), 
        [&](const string &i, const string &j){
          return set.count(i) < set.count(j); 
        } ); 


    cout << endl;
    if(F % 100 >= 10 && F % 100 <= 20){
      printf("%dth most common word(s):", F);
    }
    else if(F % 10== 1){
      printf("%dst most common word(s):", F);
    }
    else if(F % 10 == 2){
      printf("%dnd most common word(s):", F);
    }
    else if(F % 10 == 3){
      printf("%drd most common word(s):", F);
    }
    else{
      printf("%dth most common word(s):", F);
    }

    cout << endl;
    int freq = 0; 
    int add = 0; 
    string last = "thequickbrownfoxjumpsoverthelazydog12834719823479132874";
    bool printed = false;
    for(int k = strs.size() - 1; k>=0; k--){
      if(set.count(strs[k]) != set.count(last)){
        freq += 1 + add; 
        add = 0;
      } 
      else{
        add++; 
      }

      if(freq == F){
        cout << strs[k] << endl;
        printed = true;
      }
      last = strs[k]; 
    }
    
  }
}
