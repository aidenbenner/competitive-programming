#include <iostream>
#include <vector>
#define INF 1e9 

using namespace std; 

class NumArray {
public:
    vector<int> dp; 
    vector<int> a; 
    NumArray(vector<int> &nums) {
      a = nums; 
      dp.resize(nums.size()); 
      for(int i = 0; i<nums.size(); i++){
        dp[i] = INF; 
      }
    }

    int sumRange(int i, int j) {  
      //inclusive 
      if(i != 0){
        return sumRange(0,j) - sumRange(0,i-1); 
      }
      if(j == 0){
        a[j]; 
      }
      if(dp[j] != INF){
        return dp[j];
      }
      return dp[j] = sumRange(0,j-1) + a[j]; 
    }
};


int main()
{
  NumArray n; 
  vector<int> test; 
  test.push_back(1); 
  test.push_back(9); 
  test.push_back(3); 
  test.push_back(-30); 
  test.push_back(-1); 

  cout << test.sumRange(0,2)  << endl; 
  cout << test.sumRange(2,2)  << endl; 
  cout << test.sumRange(3,5)  << endl; 
  cout << test.sumRange(3,4)  << endl; 
  cout << test.sumRange(1,4)  << endl; 

}
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
