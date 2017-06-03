
#include <iostream> 
#include <vector> 

using namespace std; 
#define INF 1e9

//min heap
void insert_heap(vector<int> heap, int val)
{
  if(heap.size() == 0){
    heap.push_back(val); 
    return;
  }

  bool inserted = false; 
  int node = 0; 
  while(!inserted)
  {
    if(node >= heap.size()){
      //insert 
      heap[node] = val; 
    }
    if(val < heap[node])
    {
      node = 2 * node;
    }
    else{
      node = 2 * node + 1; 
    }
  }
}

void min_heapify(vector<int> heap)
{
  for(int i = 0; i<heap.size(); i++)
  {
    if(heap[i] > heap[2 * i]){
      //swap
    }
    if(heap[i] > heap[2 * i + 1])
    {
      //swap
      
    }


  }
}


void build_heap(vector<int> a)
{
  


  for(int i = 0; i<a.size(); i++)
  {

  }
}
