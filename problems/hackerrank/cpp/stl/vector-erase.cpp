#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N; 
  cin >> N; 
  
  vector<int> vec; 
  for(int i = 0; i<N; i++)
  {
    int k; 
    cin >> k; 
    vec.push_back(k); 
  }

  int a,b,z; 
  cin >> z; 
  cin >> a >> b; 
  z--;
  a--;
  b--; 

  vec.erase(vec.begin() + z); 
  vec.erase(vec.begin() + a, vec.begin() + b); 

  cout << vec.size() << endl;
  for(int i = 0; i<vec.size(); i++)
    cout << vec[i] << " "; 

}
