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
  ios_base::sync_with_stdio(false); 

  string enc; 
  cin >> enc;

  //find possible letter gaps

  string match = "HAILHYDRA"; 
  vector<int> possible; 
  for(int i = 0; (i + 8)<enc.length(); i++){
    if(enc[i] == enc[i + 4]){
      if(enc[i + 1] == enc[i + 8]){
        possible.push_back(i); 
      }
    }
  }

  cin >> N;
  while(N--)
  {
    string map; 
    cin >> map; 

    char curr[26]; 
    for(int i = 0; i<26; i++){
      curr[map[i] - 'A'] = 'A' + i; 
    }

    for(int i = 0; i<possible.size(); i++ ){
      bool found = true; 
      for(int k = 0; k<match.length(); k++){
        int currEnc = enc[possible[i] + k] - 'A'; 
        char mapped = curr[currEnc]; 
        if(mapped != match[k]){
          found = false; 
          break;
        }
      }
      if(found){
        for(int i = 0; i<enc.length(); i++){
          int currEnc = enc[i] - 'A'; 
          char mapped = curr[currEnc]; 
          enc[i] = mapped; 
        }
        cout << enc;
        return 0; 
      }
    }
  }
  cout << "KeyNotFoundError" << endl;

}
