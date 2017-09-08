
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int solve(vector<int>& heights, int start){
      if(start >= heights.size() - 1) return 0; 

      int curr = start + 1;
      int sum = 0;
      int maxAfter = 0; 

      while(curr < heights.size()){
        maxAfter = max(maxAfter, heights[curr]); 
        if(heights[start] < heights[curr]) {
          return sum + solve(heights, curr); 
        }
        else{
          sum += heights[start] - heights[curr]; 
        }
        curr++; 
      }
      sum -= (heights[start] - maxAfter) * (curr - start); 
      return sum;
    }

    int trap(vector<int>& height) {
      if(height.size() <= 1) return 0; 
      return solve(height, 0); 
    }

};

int main(){
  Solution s;
  vector<int> a; 
  a.push_back(4);
  a.push_back(2);
  a.push_back(3);
  cout << s.trap(a);
}
