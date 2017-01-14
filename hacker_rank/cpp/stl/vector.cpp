#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main()
{
  int N; 
  
  vector<int> vec; 
  
  cin >> N; 
  while(N--){
    int k; 
    cin >> k;
    vec.push_back(k); 
  }

  sort(vec.begin(), vec.end()); 

  for(int i = 0; i<vec.size(); i++)
  {
    cout << vec[i] << " "; 
  }
}
