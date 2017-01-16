#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstring>

#define INF 1e9 

using namespace std; 

int SP[101][101]; 
vector< pair<int,int> > fam; 
vector<vector< pair<int,int> >  > adjList;

void update_shortest(vector<vector< pair<int,int> > > adjList, int source)
{
  SP[source][source] = 0; 
  priority_queue< pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > pq; 

  pq.push(make_pair(0,source)); 

  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop(); 

    for(int i = 0; i<adjList[u].size(); i++){
      int v = adjList[u][i].first;
      int weight = adjList[u][i].second;

      if((SP[source][v] > SP[source][u] + weight)){
        SP[source][v] = SP[source][u] + weight;
        //cout << source << "  " << v << " " << SP[source][v] << " " << weight << " " << SP[source][u]  << endl;
        pq.push(make_pair(SP[source][v],v)); 
      }
    }
  }
}

//nth family 
int DP[101][5001][3]; 
int N, M, K; 
int recur(int n, int family, int ppl){
  if(family == K){
    return 0; 
  }
  if(DP[n][family][ppl] != -1){
    return DP[n][family][ppl]; 
  }
  if(ppl == 0){
    //forced to pickup next
    int pick = fam[family].first;
    return DP[n][family][ppl] = SP[n][pick] + recur(pick,family,ppl+1);
  }

  if(ppl == 1){
    //either we drop of our current guy or we pickup next
    int drop = fam[family].second;
    int pick = fam[family + 1].first; 
  
    int op1 = SP[n][drop] + recur(drop,family+1,ppl-1);
    int op2 = SP[n][pick] + recur(pick,family,ppl+1);

    if(family == K-1){
      return op1;
    }

    return DP[n][family][ppl] = min(op1, op2); 
  }

  if(ppl == 2){
    //forced to dropoff
    int drop = fam[family].second;
    return DP[n][family][ppl] = SP[n][drop] + recur(drop,family+1,ppl-1);
  }
}


int main()
{
  int T; 
  cin >> T; 
  for(int test = 1; test<=T; test++){
    cin >> N >> M >> K; 

    memset(DP, -1, sizeof(DP)); 

    adjList.clear(); 
    adjList.resize(N);  
    for(int i = 0; i<M; i++){
      int A, B, G;
      cin >> A >> B >> G; 
      A--; 
      B--; 
      adjList[A].push_back(make_pair(B,G)); 
      adjList[B].push_back(make_pair(A,G)); 
    }

    for(int i = 0; i<N; i++){
      for(int k = 0; k<N; k++){
        SP[i][k] = INF; 
      }
      SP[i][i] = 0; 
    }

    fam.clear(); 
    for(int i = 0; i<K; i++){
      int S, D; 
      cin >> S >> D;
      S--;
      D--;
      fam.push_back(make_pair(S,D)); 
    }

    for(int i = 0; i<N; i++){
      update_shortest(adjList,i); 
    }

    //check for infinite paths
    for(int i = 0; i<K; i++){
      if(SP[0][fam[i].first] == INF || SP[0][fam[i].second] == INF){
        cout << "Case #" << test << ": " << "-1" << endl;
        goto escape;
      }
    }

    cout << "Case #" << test << ": "<< recur(0,0,0) << endl;
escape:     ;
  }
}
