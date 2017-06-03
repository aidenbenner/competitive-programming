#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector< vector<int> > adjList;
int validPaths[26][26];  

int DFS(int source, vector<bool> visited) 
{
  if(source == 1){
    return 1;
  }
  int num_paths = 0; 
  visited[source] = true;
  for(int i = 0; i<adjList[source].size(); i++){
    int n = adjList[source][i]; 
    if(visited[n]){
      continue;
    }
    int out = DFS(n,visited); 
    if(out >= 1){
      num_paths += out;  
      int A = min(source,n); 
      int B = max(source,n); 
      validPaths[B][A] += out; 
    }
  }
  return num_paths;
}

int main()
{

  for(int i = 0; i<26; i++){
    for(int k = 0; k<26; k++){
      validPaths[i][k] = 0; 
    }
  }

  string comm;
  adjList.resize(26); 
  while(cin >> comm){
    if(comm[0] == '*'){
      break;
    }
    int A = comm[0] - 'A'; 
    int B = comm[1] - 'A'; 
    adjList[A].push_back(B); 
    adjList[B].push_back(A); 
  }

  vector<bool> visited;
  visited.resize(26); 
  for(int i = 0; i<26; i++){
    visited[0] = false; 
  }


  int max = DFS(0,visited); 
  int count = 0; 
  for(int i = 0; i<26; i++)
    for(int k = 0; k<26; k++)
      if(validPaths[i][k] == max){
        count++; 
        cout << (char)(i + 'A') << (char)(k + 'A') << endl; 
      }
  cout << "There are "<< count << " disconnecting roads." << endl;
}
