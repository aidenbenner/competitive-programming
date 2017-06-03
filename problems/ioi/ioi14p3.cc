#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <list>

using namespace std;


int flights[1500]; 

void initialize(int n){
  for(int i = 0; i<n; i++){
    flights[i] = n - 1;
  }
}


int hasEdge(int u, int v){
  if(flights[u] == 1){
    return 1;
  }
  if(flights[v] == 1){
    return 1; 
  }
  flights[u]--; 
  flights[v]--; 
  return 0;
} 

/**
int main()
{
  initialize(4); 
  cout << hasEdge(0,3);
  cout << endl;
  cout << hasEdge(1,0);  
  cout << endl;
  cout << hasEdge(0,2);  
  cout << endl;
  cout << hasEdge(3,1);  
  cout << endl;
  cout << hasEdge(1,2);  
  cout << endl;
  cout << hasEdge(2,3);  
}**/ 
