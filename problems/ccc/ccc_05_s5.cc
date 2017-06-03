#include <set>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  multiset<int> mp; 

  int T; 
  cin >> T;
  
  double total = 0; 
  for(int i = 1; i<=T; i++){
    int x; 
    cin >> x; 
    mp.insert(x); 

    int rank = 0; 
    auto itr = mp.find(x);
    total += (mp.count(x) - 1) + distance(itr, mp.end());
  }
  total = total / (double)T; 
  total = round(100 * total) / 100;   
  printf("%.2lf", total); 
}
