#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>


#define INF 1e9
#define EPS 1e-13
#define pb push_back

using namespace std;

typedef vector<vector<pair<int,int>>> Adjlist;
typedef unsigned long long ull;
typedef long long ll;

int N; 
int main()
{
  while(true){
    cin >> N;
    if(N == 0) return 0; 

    if(N==1){
      int waste;
      cin >> waste;
      cout << 0 << endl;
      continue;
    } 

    int last = 0; 
    cin >> last;

    N--;
    int diff[N]; 
    for(int i = 0; i<N ; i++){
      int next;
      cin >> next; 
      diff[i] = next - last;
      last = next;
      //cout << diff[i] << "  "; 
    }

    bool solved = false;
    for(int i = 1; i<=N; i++){
      // 0 .. i == cycle
      solved = true;
      //cout << i << " i " << endl;
      for(int k = 0; i+k<N; k++){
        // cout << diff[k %i] << "  " << diff[i+k] << endl;
        if(diff[k % i] != diff[i + k]){
          solved = false;
          break;
        }
      }
      if(solved){
        cout << i << endl;
        break;
      }
    }
    if(!solved){
      cout << N << endl;
    }
  }
}
