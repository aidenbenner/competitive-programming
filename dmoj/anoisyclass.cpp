#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std; 


int N; 
int M; 
int main()
{
  cin >> N >> M; 
  vector< list<int> > adjList; 
  adjList.resize(N); 

  for(int i = 0; i<M; i++){
    int a, b; 
    cin >> a >> b; 
    adjList[a].push_back(b); 
  }

}
