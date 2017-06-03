#include <vector>
#include <iostream>
using namespace std;
class Solution {
  public:
    bool isSelfCrossing(vector<int>& x) {
      for(int i = 0; i<x.size() - 3; i++){
        if(x[i] >= x[i + 2]){
          if(x[i + 3] >= x[i + 1]){
            return true;
          }
        }
      }   
      return false;
    }


};

int main()
{
  Solution s; 
  vector<int> x;
  x.push_back(1); 
  x.push_back(1); 
  x.push_back(1); 
  x.push_back(1); 
  cout << s.isSelfCrossing(x); 

}
