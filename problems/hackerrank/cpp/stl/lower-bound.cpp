#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
  int N; 
  cin >> N; 

  vector<int> vec; 
  
  for(int i = 0; i<N; i++){
    int k; 
    cin >> k; 
    vec.push_back(k); 
  }

  int Q, Y;

  cin >> Q; 
  for(int i = 0; i<Q; i++){
    cin >> Y; 

    auto out = lower_bound(vec.begin(), vec.end(), Y); 
    if(vec[out- vec.begin()] == Y)
      cout << "Yes ";
    else{
      cout << "No "; 
    }
    cout << out - vec.begin() + 1 << endl;
  }


}
