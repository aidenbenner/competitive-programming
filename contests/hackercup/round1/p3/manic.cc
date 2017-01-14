#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define INF 1e9 

using namespace std; 




vector< vector<int> > SP; 

void update_shortest(vector<vector< pair<int,int> > > adjList, int source, int dest)
{
  for(int i = 0; i<SP.size(); i++) SP[source][i] = -1; 

  SP[source][source] = 0; 
  priority_queue< pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > pq; 

  pq.push(make_pair(0,source)); 

  while(!pq.empty()){
    int u = pq.top().second;

    for(int i = 0; i<adjList[u].size(); i++){
      int v = adjList[u][i].first;
      int weight = adjList[u][i].second;

      if(SP[source][v] < SP[source][u] + weight || SP[source][v] == -1){
        SP[source][dest] = SP[source][u] + weight;
        pq.push(make_pair(SP[source][v],v)); 
      }
    }
  };
}

int main()
{
  int T; 
  cin >> T; 
  for(int test = 1; test<=T; test++){
    int N, M, K; 
    cin >> N >> M >> K; 

    vector<vector< pair<int,int> >  > adjList;

    adjList.resize(N); 
    for(int i = 0; i<M; i++){
      int A, B, G;
      cin >> A >> B >> G; 
      adjList[A].push_back(make_pair(B,G)); 
      adjList[B].push_back(make_pair(A,G)); 
    }

    SP.resize(N); 
    for(int i = 0; i<N; i++){
      SP[i].resize(N); 
      for(int k = 0; k<N; k++){
        SP[i][k] = -1; 
      }
      SP[i][i] = 0; 
    }

    vector< pair<int,int> > fam; 
    for(int i = 0; i<K; i++){
      int S, D; 
      cin >> S >> D;
      fam.push_back(make_pair(S,D)); 
    }

    for(int i = 0; i<K; i++){
      update_shortest(adjList,fam[i].first,fam[i].second); 
    }


    int gas = 0; 
    int target = 0; 
    int location = 0; 
    int loaded = 0; 
    for(int i = 0; i<K; i++){
      if(loaded == 0){
        gas += SP[location][fam[target].first];
        location = fam[target].first; 
        loaded++; 
      }
      if(loaded == 1){
        int drop = fam[target].second;
        int pick = fam[target + 1].first; 
        int op1 = SP[location][drop] + SP[drop][pick];
        int op2 = SP[location][pick] + SP[pick][drop];



      }
      if(loaded == 2){
        gas += SP[location][fam[target].second];
        location = fam[target].second;
        target++; 
        loaded--; 
      }
    }


  }

}
