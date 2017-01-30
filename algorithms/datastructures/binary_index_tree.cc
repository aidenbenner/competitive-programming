#include <iostream>

using namespace std;


const int size = 2000; 

int tree[size]; 

void init()
{
  for(int i = 0; i<size; i++){
    tree[i] = 0; 
  }
}

int sum(int b)
{
  int sum = 0;
  for(; b; b -= (b & -b)) sum += tree[b]; 
  return sum;
}

int sum(int a, int b)
{
  return sum(b) - (a == 1 ? 0 : sum(a - 1)); 
}

void update(int k, int v)
{
  for(; k<=size; k+= (k & -k)) tree[k] += v; 
}

int main()
{
  init(); 
  update(5,10); 
  cout << update(0,100) << endl; 
}
