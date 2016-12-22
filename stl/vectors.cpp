#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main()
{
  vector<int> vec; 

  vec.push_back(5); 
  vec.push_back(12); 
  vec.push_back(-30); 
  vec.push_back(45); 
  vec.push_back(10); 

  sort(vec.begin()+2, vec.end() - 1);

  for(int i = 0; i<vec.size(); i++){
    cout << vec[i] << " "; 
  }

}
