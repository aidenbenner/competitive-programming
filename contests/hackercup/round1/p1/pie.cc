#include <vector>
#include <algorithm>
#include <iostream>

#define INF 1e9 
using namespace std;


int N, M; 
int main()
{
  int T; 
  cin >> T; 

  for(int test = 1; test <= T; test++){
    vector< vector<int> > pies; 
    cin >> N >> M; 

    pies.resize(N); 
    for(int i = 0; i<N; i++){
      pies[i].resize(M); 
      for(int k = 0; k<M; k++){
        cin >> pies[i][k]; 
      }
      sort(pies[i].begin(), pies[i].end()); 
    }

    int bought[N]; 
    for(int i = 0; i<N; i++){
      bought[i] = 0; 
    }

    int cost = 0; 

    int used = 0; 
    int curr_day = 1; 
    int cost_min = INF; 
    for(int i = 0; i<N; i++){
      //find min for each day 
      cost_min = INF;
      for(int k = 0; k<curr_day; k++){
        int ind = bought[k]; 
        if(bought[k] >= pies[k].size()){
          continue;
        }
        int curr_cost = pies[k][ind] + (bought[k] + 1) * (bought[k] + 1) - (bought[k] * bought[k]); 
        if(curr_cost < cost_min){
          used = k; 
          cost_min = curr_cost; 
        }
      }
      curr_day++; 
      bought[used]++;
      cost += cost_min; 
    }
    cout << "Case #"<< test << ": " << cost << endl;
  }
}

