

#include <cmath> 
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      vector<int> out;

      int itr = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

      int i = itr; 
      int j = itr - 1; 

      // tie smaller elements prefered 

      for(int z = 0; z<k; z++){
        int diffA = abs(arr[i] - x); 
        int diffB = abs(arr[j] - x); 

        if((diffA < diffB || j < 0) && i < arr.size()){
          i++; 
        }
        else {
          j--;
        }
      }

      for(int z = 0; z<k; z++){
        out.push_back(arr[j + z + 1]);
      }

      return out;
    }
};


int main(){
  Solution s;
  vector<int> a;
  a.push_back(0);
  a.push_back(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(3);
  a.push_back(4);
  a.push_back(7);
  a.push_back(7);
  a.push_back(8);
  auto out = s.findClosestElements(a, 3, 5); 
  for(int i = 0; i<out.size(); i++){
    cout << out[i] << endl;
  }
}




