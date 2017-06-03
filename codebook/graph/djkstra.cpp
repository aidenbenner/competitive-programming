#include <iostream>
#include <functional>
#include <cstdio>
#include <queue> 
#include <vector> 
#include <string> 

using namespace std;



int main(){
  priority_queue<int> pq; 
  pq.push(5); 
  pq.push(2); 
  pq.push(1); 
  pq.push(9); 
  pq.push(8); 
  pq.push(3); 

  printf("%d\n", pq.top()); 
}
