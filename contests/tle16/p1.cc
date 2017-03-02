#include <iostream>
#include <algorithm>
#include <string> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>

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
  map<string, int> mp; 

  cin >> N;
  for(int i = 0; i<N; i++){
    string next;
    cin >> next;
    mp[next] = i; 
  }

  int K;
  cin >> K;


  priority_queue<pair<int,int>> pq; 

  for(int i = 1; i<=K; i++){
    string next;
    cin >> next;
    pq.push(make_pair(-mp[next],-i));
  }


  while(!pq.empty()){
    cout << -pq.top().second << endl;
    pq.pop();
  }
}
